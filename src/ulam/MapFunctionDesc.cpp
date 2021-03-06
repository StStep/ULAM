#include "MapFunctionDesc.h"
#include "CompilerState.h"

namespace MFM {

  FunctionDesc::FunctionDesc(SymbolFunction * fsym, UTI classtype, CompilerState & state) : ClassMemberDesc(fsym, classtype, state)
  {
    m_mangledMemberName = ""; //clears base init
    m_mangledMemberName = fsym->getMangledNameWithTypes();
  }

  FunctionDesc::FunctionDesc(const FunctionDesc& fref) : ClassMemberDesc(fref) {}

  FunctionDesc::~FunctionDesc() {}

  const ClassMemberDesc *  FunctionDesc::clone() const
  {
    return new FunctionDesc(*this);
  }

  std::string FunctionDesc::getMemberKind() const
  {
    return "FUNCTION";
  }


} //MFM
