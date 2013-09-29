#include <string>
#include "Tokenizer.h"

using namespace std;

class StringCalculator{
public:
  StringCalculator(Tokenizer* inputTokenizer);
  ~StringCalculator();
  double calculate(string inputString);
  
private:
  StringCalculator(const StringCalculator&);
  StringCalculator& operator=(const StringCalculator&);

  Tokenizer* inputStringTokenizer;
};