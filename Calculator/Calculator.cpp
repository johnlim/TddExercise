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

#include <iostream>
int Calculator::parse( std::string str )
{
  int count=0;

  for(unsigned int i=0; i < str.length(); i++ ){
    if( str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' ) {
      count++;
    }
  }

  int first_position = str.find_first_of("0123456789");
  int first_positionOfNonNumer = str.find_first_of("-");
  if ((first_positionOfNonNumer != -1) && (first_positionOfNonNumer < first_position))
  {
    count--;
  }

  return count*2 + 1;
}

std::string Calculator::stripWhiteSpaces( std::string str )
{
  std::string result;
  for (size_t i = 0; i < str.length(); i++)
  {
    if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
      result.push_back(str[i]);
  }
  return result;
}

#include <vector>
using namespace std;


size_t Calculator::returnNumberOfTokens( std::string str )
{
  vector<string> sv;
  string str2;

  for (size_t i = 0; i< str.length(); i++ )
  {
      if(str[i] >= '0' && str[i] <= '9'){
        str2.push_back(str[i]);
      }else{
        sv.push_back(str2);
        sv.push_back(string(1, str[i]));
        str2.clear();
      }
  }
  sv.push_back(str2);


  return sv.size();
}