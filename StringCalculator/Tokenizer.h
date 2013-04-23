#ifndef _MyTokenizer_H_
#define _MyTokenizer_H_

#include <string>
#include <list>
//
using namespace std;

class MyTokenizer{
public:
  list<string> tokenize(std::string inputString);
};

#endif //_MyTokenizer_H_