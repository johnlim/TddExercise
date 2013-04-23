#include "StringCalculator.h"
#include "Tokenizer.h"

StringCalculator::StringCalculator()
{

}

double StringCalculator::calculate(string inputString)
{
  MyTokenizer inputTokens;
  list<string> inputTokenizedString = inputTokens.tokenize(inputString);
  return 3;
}