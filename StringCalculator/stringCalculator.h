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
	void stringCalculator::handleMulitplication(list<wstring>& inputString, list<wstring>::iterator& listIterator);
  void stringCalculator::handleAddition(list<wstring>& inputString, list<wstring>::iterator& listIterator);
};