#include "TestCase_EndToEndCompiler.h"

namespace MFM {

  BEGINTESTCASECOMPILER(t3134_test_compiler_funccall_noargs)
  {
    std::string GetAnswerKey()
    {
      //a.ulam:1:45: ERROR: (3) <foo> has 1 arguments for a defined function, that has 0 parameters.

      return std::string(" { Int a(0);  Int main() {  ( )foo } }\n");
    }
    
    std::string PresetTest(FileManagerString * fms)
    {
      bool rtn1 = fms->add("a.ulam","ulam { Int a; Int foo() { 1; } Int main() { foo(); } }");
            
      if(rtn1)
	return std::string("a.ulam");
      
      return std::string("");
    }
  }
  
  ENDTESTCASECOMPILER(t3134_test_compiler_funccall_noargs)
  
} //end MFM


