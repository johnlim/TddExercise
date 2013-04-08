#include "CppUTest/TestHarness.h"
#include <string>
#include <list>
#include <cstring>
#include "Tokenizer.h"

using namespace std;

TEST_GROUP(TOKENIZER)
{
	Tokenizer stringTokenizer;
};

TEST(TOKENIZER, testTokenizerSplitsStringIntoTokensUsingMultiplySymbolAsSeparator)
{
	wstring inputString(L"3*4");
	list<wstring> tokenizedString = stringTokenizer.tokenize(inputString);
	list<wstring>::iterator listIterator = tokenizedString.begin();
	STRCMP_EQUAL("3", (*listIterator).c_str());
}
