#include "stringCalculator.h"
#include <iostream>

wstring stringCalculator::calculate(list<wstring> inputString)
{
	handleMulitplication(inputString);
  handleAddition(inputString);
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

void stringCalculator::handleMulitplication(list<wstring>& inputString)
{
	list<wstring>::iterator listIterator = inputString.begin();
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
}

void stringCalculator::handleAddition(list<wstring>& inputString)
{
	list<wstring>::iterator listIterator = inputString.begin();
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
}
