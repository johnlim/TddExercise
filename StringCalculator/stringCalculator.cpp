#include "stringCalculator.h"
#include <iostream>

wstring stringCalculator::calculate(list<wstring> inputString)
{
  long double result = 0;
  wstring resultString = L"Error";
  list<wstring> cache(inputString);
  int i = 0;
  /*for( list<wstring>::iterator listIterator = inputString.begin(); listIterator != inputString.end(); listIterator++)
  {    
    if(*listIterator == L"+") {
      result = leftOperand(listIterator) + rightOperand(listIterator);
      resultString = std::to_wstring(result);
      *next(listIterator) = resultString; 
      listIterator = inputString.begin();
      for(int x = 0; x < i; x++) {
        listIterator++;
      }
      inputString.erase(prev(listIterator), next(listIterator));
      break;
    } 
    i++;
  }*/
  list<wstring>::iterator listIterator = inputString.begin();
  while (inputString.size() > 1) 
  {
    if(*listIterator == L"*") 
    {
      HandleMulitplication(inputString, listIterator);
      continue;
    }
    else if(*listIterator == L"+") 
    {
      result = leftOperand(listIterator) + rightOperand(listIterator);
      resultString = std::to_wstring(result);
      *next(listIterator) = resultString;
      inputString.erase(prev(listIterator), next(listIterator));      
      listIterator = inputString.begin();
      continue;
    }
    listIterator++;
  }
  return *inputString.begin();
  
  
}

double stringCalculator::leftOperand(list<wstring>::iterator listIterator)
{
  wstring::size_type stringtypesize;
  return stod(*(prev(listIterator)),  &stringtypesize);
}

double stringCalculator::rightOperand(list<wstring>::iterator listIterator)
{
  wstring::size_type stringTypeSize;
  return stod(*(next(listIterator)),  &stringTypeSize);
}

void stringCalculator::HandleMulitplication(list<wstring>& inputString, list<wstring>::iterator& listIterator)
{
	wstring resultString = L"Error";
	long double result = leftOperand(listIterator) * rightOperand(listIterator);
	resultString = std::to_wstring(result);
	*next(listIterator) = resultString;
	inputString.erase(prev(listIterator), next(listIterator));      
	listIterator = inputString.begin();
}