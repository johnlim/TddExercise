#include <string>
#include <list>
#include <iterator>

using namespace std;

class stringCalculator {
public:
  wstring calculate(list<wstring> inputString);
private:
  double leftOperand(list<wstring>::iterator listIterator);
  double rightOperand(list<wstring>::iterator listIterator);
	void stringCalculator::handleMultiplication(list<wstring>& inputString);
  void stringCalculator::handleDivision(list<wstring>& inputString);
  void stringCalculator::handleAddition(list<wstring>& inputString);
};