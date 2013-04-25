#ifndef _MyTokenizer_H_
#define _MyTokenizer_H_

#include <string>
#include <list>
//
using namespace std;

class Tokenizer{
public:
  virtual list<string> tokenize(std::string inputString) = 0;
};

#endif //_MyTokenizer_H_