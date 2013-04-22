#include <string>

using namespace std;

class StringCalculator{
public:
  StringCalculator();
  double calculate(string inputString);
private:
  StringCalculator(const StringCalculator&);
  StringCalculator& operator=(const StringCalculator&);
};