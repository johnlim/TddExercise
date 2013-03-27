#include "stringCalculator.h"
#include <iostream>

wstring stringCalculator::calculate(list<wstring> inputString)
{
  long double result = 0;
  wstring resultString = L"Error";
 
  list<wstring>::iterator listIterator = inputString.begin();
  
    handleMulitplication(inputString, listIterator);
    handleAddition(inputString, listIterator);
    
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

void stringCalculator::handleMulitplication(list<wstring>& inputString, list<wstring>::iterator& listIterator)
{
	//list<wstring>::iterator cacheIterator = listIterator;
	while( listIterator != inputString.end())
	{
		if (*listIterator == L"*") {
			wstring resultString = L"Error";
			long double result = leftOperand(listIterator) * rightOperand(listIterator);
			resultString = std::to_wstring(result);
			*next(listIterator) = resultString;
			inputString.erase(prev(listIterator), next(listIterator));      
			listIterator = inputString.begin();
			continue;
		}
		listIterator++;
	}
	listIterator = inputString.begin();
}

void stringCalculator::handleAddition(list<wstring>& inputString, list<wstring>::iterator& listIterator)
{
  while( listIterator != inputString.end()) {
    if(*listIterator == L"+") 
    {
      long double result = leftOperand(listIterator) + rightOperand(listIterator);
      wstring resultString = std::to_wstring(result);
      *next(listIterator) = resultString;
      inputString.erase(prev(listIterator), next(listIterator));      
      listIterator = inputString.begin();
      continue;
    }
   listIterator++;
  }
  listIterator = inputString.begin();
}
