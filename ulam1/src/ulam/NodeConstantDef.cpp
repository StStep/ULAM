#include <stdlib.h>
#include "NodeConstantDef.h"
#include "CompilerState.h"


namespace MFM {

  NodeConstantDef::NodeConstantDef(SymbolConstantValue * symptr, CompilerState & state) : Node(state), m_constSymbol(symptr), m_exprnode(NULL), m_currBlock(state.m_currentBlock) {}

  NodeConstantDef::~NodeConstantDef()
  {
    delete m_exprnode;
    m_exprnode = NULL;
  }

  void NodeConstantDef::updateLineage(Node * p)
  {
    setYourParent(p);
    m_exprnode->updateLineage(this);
  }


  void NodeConstantDef::printPostfix(File * fp)
  {
    m_exprnode->printPostfix(fp);
    fp->write(" = ");
    fp->write(getName());
    fp->write(" const");
  }


  const char * NodeConstantDef::getName()
  {
    return m_state.m_pool.getDataAsString(m_constSymbol->getId()).c_str();
  }


  const std::string NodeConstantDef::prettyNodeName()
  {
    return nodeName(__PRETTY_FUNCTION__);
  }


  bool NodeConstantDef::getSymbolPtr(Symbol *& symptrref)
  {
    symptrref = m_constSymbol;
    return true;
  }


  UTI NodeConstantDef::checkAndLabelType()
  {
    UTI it = Nav;
    it = m_exprnode->checkAndLabelType();
    if(!(it == m_state.getUlamTypeOfConstant(Int) || it == m_state.getUlamTypeOfConstant(Unsigned)))
      {
	std::ostringstream msg;
	msg << "Constant value expression for: " << m_state.m_pool.getDataAsString(m_constSymbol->getId()).c_str() << ", has an invalid type: <" << m_state.getUlamTypeNameByIndex(it) << ">";
	MSG(getNodeLocationAsString().c_str(), msg.str().c_str(), ERR);
	it = Nav;
      }
    setNodeType(it);
    return getNodeType();
  } //checkAndLabelType


  void NodeConstantDef::countNavNodes(u32& cnt)
  {
    Node::countNavNodes(cnt);
    m_exprnode->countNavNodes(cnt);
  }


  void NodeConstantDef::setConstantExpr(Node * node)
  {
    m_exprnode = node;
  }


  // called during parsing rhs of named constant
  // Requires a constant expression, else error;
  // (scope of eval is based on the block of const def.)
  bool NodeConstantDef::foldConstantExpression()
  {
    //    NodeBlock * savecurrentblock = m_state.m_currentBlock; //**********
    s32 newconst = NONREADYCONST;  //always signed?
    UTI uti = checkAndLabelType(); //getNodeType()
    if((uti == m_state.getUlamTypeOfConstant(Int) || uti == m_state.getUlamTypeOfConstant(Unsigned)))
    {
	//	m_state.m_currentBlock = m_currBlock;
	evalNodeProlog(0); //new current frame pointer
	makeRoomForNodeType(getNodeType()); //offset a constant expression
	m_exprnode->eval();
	UlamValue cnstUV = m_state.m_nodeEvalStack.popArg();
	evalNodeEpilog();

	if(cnstUV.getUlamValueTypeIdx() == Nav)
	  newconst = NONREADYCONST;
	else
	  newconst = cnstUV.getImmediateData(m_state);

	//m_state.m_currentBlock = savecurrentblock; //restore

	if(newconst == NONREADYCONST)
	  {
	    std::ostringstream msg;
	    msg << "Constant value expression for: " << m_state.m_pool.getDataAsString(m_constSymbol->getId()).c_str() << ", is not yet \"ready\"";
	    MSG(getNodeLocationAsString().c_str(), msg.str().c_str(), WARN);
	    return false;
	  }
      }
    else
      {
	std::ostringstream msg;
	msg << "Constant value expression for: " << m_state.m_pool.getDataAsString(m_constSymbol->getId()).c_str() << ", is not a constant expression";
	MSG(getNodeLocationAsString().c_str(), msg.str().c_str(), ERR);
	return false;
      }
    // passed
    m_constSymbol->setValue(newconst); //isReady now

    return true;
  } //foldConstantExpr


  EvalStatus NodeConstantDef::eval()
  {
    if(m_constSymbol->isReady())
      return NORMAL;
    return ERROR;
  }


  void NodeConstantDef::genCode(File * fp, UlamValue& uvpass)
  {}



} //end MFM

