#include <string>

class Calculator {
public:
  int calculate( std::string str );
  int parse( std::string str );
  std::string stripWhiteSpaces( std::string str ); 
  size_t returnNumberOfTokens( std::string str  );
};