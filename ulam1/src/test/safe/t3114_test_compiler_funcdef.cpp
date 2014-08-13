#include "TestCase_EndToEndCompiler.h"

namespace MFM {

  BEGINTESTCASECOMPILER(t3114_test_compiler_funcdef)
  {
    std::string GetAnswerKey()
    {
      return std::string(" { Int d(1);  Int main() {  Bool mybool[3];  mybool 0 [] true = mybool 1 [] false = mybool 2 [] false = d ( 7 mybool )m = } }\n");
    }
    
    std::string PresetTest(FileManagerString * fms)
    {
      bool rtn1 = fms->add("a.ulam","ulam { Int m(Int m, Bool b[3]) { if(b[0]) m=1; else m=2; m;} Int main() { Bool mybool[3]; mybool[0] = true; mybool[1] = false; mybool[2]= false; d = m(7, mybool); } Int d; }");  // want d == 1.
      
      if(rtn1)
	return std::string("a.ulam");
      
      return std::string("");
    }
  }
  
  ENDTESTCASECOMPILER(t3114_test_compiler_funcdef)
  
} //end MFM


