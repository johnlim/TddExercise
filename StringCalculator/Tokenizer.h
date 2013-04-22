#include <string>
#include <list>

using namespace std;

class Tokenizer {
public:
	Tokenizer();
	list<wstring> tokenize(wstring);
private:
	Tokenizer(const Tokenizer&);
	Tokenizer& operator=(const Tokenizer&);
};