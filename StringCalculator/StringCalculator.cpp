#include "StringCalculator.h"
#include "StringCalculatorTokenizer.h"

StringCalculator::StringCalculator(Tokenizer* inputTokenizer) 
                 :inputStringTokenizer(inputTokenizer)
{
  
}

double StringCalculator::calculate(string inputString) //realised that calculate does more than just calculate. Its also tokenizing. Time to extract out tokenize.
{
  list<string> inputTokenizedString = inputStringTokenizer->tokenize(inputString);
  list<string>::iterator listIterator = inputTokenizedString.begin();

  double leftOperand, rightOperand;
  
  leftOperand = stod(*listIterator);
  listIterator++;
  listIterator++;
  rightOperand = stod(*listIterator);
  return (leftOperand + rightOperand);
}

StringCalculator::~StringCalculator()
{
  
}
