#include "CppUTest/TestHarness.h"
#include "StringCalculator.h"

TEST_GROUP(StringCalculator)
{
  enum {tolerance=0};
};

TEST(StringCalculator, TestAdditionOfTwoPositiveIntegerNumbersOnly)
{
  StringCalculator stringCalculator;
  DOUBLES_EQUAL(3, stringCalculator.calculate("1+2"), tolerance);
}
  
TEST(StringCalculator, TestAdditionOfTwoDoubleNumbersOnly)
{
  StringCalculator stringCalculator;
  DOUBLES_EQUAL(3.5, stringCalculator.calculate("1+2.5"), tolerance);
}