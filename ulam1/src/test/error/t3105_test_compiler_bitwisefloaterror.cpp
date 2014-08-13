#include "TestCase_EndToEndCompiler.h"

namespace MFM {

  BEGINTESTCASECOMPILER(t3105_test_compiler_bitwisefloaterror)
  {
    std::string GetAnswerKey()
    {
      return std::string("a.ulam:1:59: ERROR: Invalid Operands of Types: Float and Float to binary operator^.\na.ulam:1:1: fyi: 1 TOO MANY TYPELABEL ERRORS.\n { Int main () { Float a(3.200000);  Float b(2.100000);  Float c(Nav.8.0);  Bool d(Nav.8.0);  a 3.2 = b 2.1 = d c a b ^ cast = cast = c} }\n");
    }
    
    std::string PresetTest(FileManagerString * fms)
    {
      bool rtn1 = fms->add("a.ulam","ulam { use main; Float a, b, c; Bool d; a = 3.2; b = 2.1; d = c = a ^ b; c;} }");
      bool rtn2 = fms->add("main.ulam", "Int main() {");      

      if(rtn1 & rtn2)
	return std::string("a.ulam");
      
      return std::string("");
    }
  }
  
  ENDTESTCASECOMPILER(t3105_test_compiler_bitwisefloaterror)
  
} //end MFM


