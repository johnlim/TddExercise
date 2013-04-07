#include "stringCalculator.h"
#include <iostream>

static void foldResultIntoList(long double result, list<wstring>& inputString, list<wstring>::iterator& listIterator);

stringCalculator::stringCalculator()
{

}

wstring stringCalculator::calculate(list<wstring> inputString)
{
  //first handle multiplication
	handleMultiplication(inputString);
  //then handle division
  handleDivision(inputString);
  handleAddition(inputString);
	handleMinus(inputString);
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

void stringCalculator::handleMultiplication(list<wstring>& inputString)
{
	list<wstring>::iterator listIterator = inputString.begin();
	while( listIterator != inputString.end())
	{
		if (*listIterator == L"*") {
			long double result = leftOperand(listIterator) * rightOperand(listIterator);
      foldResultIntoList(result, inputString, listIterator);
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
      foldResultIntoList(result, inputString, listIterator);
			listIterator = inputString.begin();
      continue;
    }
   listIterator++;
  }
}

void stringCalculator::handleDivision(list<wstring>& inputString)
{
  list<wstring>::iterator listIterator = inputString.begin();
  while( listIterator != inputString.end()) {
    if(*listIterator == L"/") 
    {
      long double result = leftOperand(listIterator) / rightOperand(listIterator);
      foldResultIntoList(result, inputString, listIterator);
			listIterator = inputString.begin();
      continue;
    }
   listIterator++;
  }
}

void stringCalculator::handleMinus(list<wstring>& inputString)
{
	list<wstring>::iterator listIterator = inputString.begin();
  while( listIterator != inputString.end()) {
    if(*listIterator == L"-") 
    {
      long double result = leftOperand(listIterator) - rightOperand(listIterator);
      foldResultIntoList(result, inputString, listIterator);
			listIterator = inputString.begin();
      continue;
    }
   listIterator++;
  }

}

void foldResultIntoList(long double result, list<wstring>& inputString, list<wstring>::iterator& listIterator)
{
  wstring resultString = std::to_wstring(result);
	*next(listIterator) = resultString;
	inputString.erase(prev(listIterator), next(listIterator));      
}