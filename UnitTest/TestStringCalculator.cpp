#include "CppUTest/TestHarness.h"
#include "StringCalculator.h"
#include "Tokenizer.h"
#include <list>
#include <string>
#include <iostream>
using namespace std;

class StubTokenizer : public Tokenizer{
public:
  virtual list<string> tokenize(std::string inputString)
  {
    return tokenList;
  }
  void setTokenList(list<string> customTokenList)
  {
    tokenList = customTokenList;
  }
private:
  list<string> tokenList;
};

TEST_GROUP(StringCalculator)
{
  enum {tolerance=0};
  StubTokenizer stubTokenizer;
  list<string> customList;
};

TEST(StringCalculator, TestAdditionOfTwoPositiveIntegerNumbersOnly)
{
  customList.clear();
  customList.push_back("1");
  customList.push_back("+");
  customList.push_back("2");

  stubTokenizer.setTokenList(customList);  
  StringCalculator stringCalculator(&stubTokenizer);
  DOUBLES_EQUAL(3, stringCalculator.calculate("1+2"), tolerance);
}
  
TEST(StringCalculator, TestAdditionOfTwoDoubleNumbersOnly)
{
  StubTokenizer stubTokenizer;
  customList.clear();
  customList.push_back("1");
  customList.push_back("+");
  customList.push_back("2.5");

  stubTokenizer.setTokenList(customList);  
  StringCalculator stringCalculator(&stubTokenizer);
  DOUBLES_EQUAL(3.5, stringCalculator.calculate("1+2.5"), tolerance);
}