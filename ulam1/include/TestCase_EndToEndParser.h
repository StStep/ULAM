/* -*- c++ -*- */

#ifndef TESTCASEENDTOENDPARSER_H
#define TESTCASEENDTOENDPARSER_H

#include <string.h>
#include "File.h"
#include "FileString.h"
#include "FileManagerString.h"
#include "TestCase_EndToEndIO.h"

#define BEGINTESTCASEPARSER(n)				\
  struct TestCase_##n : public TestCase_EndToEndParser

#define ENDTESTCASEPARSER(n) ; static TestCase_##n the_instance;	\
  TestCase * n = &the_instance;

namespace MFM{

  class TestCase_EndToEndParser : public TestCase_EndToEndIO
  {
  public:

    virtual ~TestCase_EndToEndParser(){}

     /** setup test; return the string to start with */
    virtual std::string PresetTest(FileManagerString * fms) = 0;

    /** runs the test; returns true with results in output; false when error in output  */
    virtual bool GetTestResults(FileManager * fm, std::string startstr, File * output);    
    
    /** checks the results using the answer key to compare with */
    virtual bool CheckResults(FileManagerString * fms, File * output);


  protected:  

    virtual std::string GetAnswerKey() = 0;

    private:

  };

}

#endif //end TESTCASEENDTOENDPARSER_H
