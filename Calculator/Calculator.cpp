#include "Calculator.h"
#include "stdlib.h"

int Calculator::calculate( std::string str )
{
  std::string operands[2];
  int operandposition = 0;
  for (unsigned int i = 0; i < str.length(); i++)
  {
    if (str[i] >= '0' && str[i] <= '9')
      operands[operandposition].push_back(str[i]);
    else if (str[i] == ' ');
    else
      operandposition++;
  }
  if (operandposition == 0)
    return atoi(operands[0].c_str());

  return (atoi(operands[0].c_str()) + atoi(operands[1].c_str()));
}