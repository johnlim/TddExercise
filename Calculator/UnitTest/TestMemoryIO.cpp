#include "CppUTest\TestHarness.h"

//C++ MemoryIO - comment out for now. To clean up.
//class MemoryIO{
//public:
//  MemoryIO(){}
//  void setAddress(int* address){_address = address;}
//  void setData(int data){_data = data;}
//  void writeData(){*_address = _data;}
//  int readData(){return *_address;}
//private:
//  MemoryIO(const MemoryIO&);
//  MemoryIO& operator=(const MemoryIO&);
//  int* _address;
//  int _data;
//};
//
//char wcharToAscii(int wchar)
//{
//  return (char)wchar;
//}
//
//TEST_GROUP(BOARD_TEST)
//{
//  MemoryIO boardTester;
//  int myFakeRegister;
//};
//
//TEST(BOARD_TEST, writeDataWritesIntendedDataToCorrectAddressLocation)
//{
//  boardTester.setAddress(&myFakeRegister);
//  boardTester.setData(0xAA55);
//  boardTester.writeData();
//  LONGS_EQUAL(0xAA55, *(&myFakeRegister));
//  LONGS_EQUAL(0xAA55, boardTester.readData());
//}
//
//TEST(BOARD_TEST, readDataReadsBackCorrectData)
//{    
//  boardTester.setAddress(&myFakeRegister);
//  boardTester.setData(0xAA55AA55);
//  boardTester.writeData();
//  LONGS_EQUAL(0xAA55AA55, boardTester.readData());
//}
//
//
//TEST(BOARD_TEST, convertsWideCharToAsciiByteForCharacters0to9AndAtoF)
//{  
//  LONGS_EQUAL('0', wcharToAscii(L'0'));
//  LONGS_EQUAL('1', wcharToAscii(L'1'));
//  LONGS_EQUAL('2', wcharToAscii(L'2'));
//  LONGS_EQUAL('3', wcharToAscii(L'3'));
//  LONGS_EQUAL('4', wcharToAscii(L'4'));
//  LONGS_EQUAL('5', wcharToAscii(L'5'));
//  LONGS_EQUAL('6', wcharToAscii(L'6'));
//  LONGS_EQUAL('7', wcharToAscii(L'7'));
//  LONGS_EQUAL('8', wcharToAscii(L'8'));
//  LONGS_EQUAL('9', wcharToAscii(L'9'));
//  LONGS_EQUAL('a', wcharToAscii(L'a'));
//  LONGS_EQUAL('b', wcharToAscii(L'b'));
//  LONGS_EQUAL('c', wcharToAscii(L'c'));
//  LONGS_EQUAL('d', wcharToAscii(L'd'));
//  LONGS_EQUAL('e', wcharToAscii(L'e'));
//  LONGS_EQUAL('f', wcharToAscii(L'f'));
//  LONGS_EQUAL('A', wcharToAscii(L'A'));
//  LONGS_EQUAL('B', wcharToAscii(L'B'));
//  LONGS_EQUAL('C', wcharToAscii(L'C'));
//  LONGS_EQUAL('D', wcharToAscii(L'D'));
//  LONGS_EQUAL('E', wcharToAscii(L'E'));
//  LONGS_EQUAL('F', wcharToAscii(L'F'));
//}
//
//IGNORE_TEST(BOARD_TEST, convertsWideCharStringToAsciiString)
//{
//  s
//}


//MemoryIO.h
#ifdef __cplusplus
extern "C"{
#endif
int* _address;
int _data;
	void setAddress(int* address);
	void setData(int data);
	void writeData(void);
	int readData(void);
#ifdef __cplusplus
}
#endif

void setAddress(int* address)
{
	_address = address;
}

void setData(int data)
{
	_data = data;
}

void writeData(void)
{
	*_address = _data;
}

int readData(void)
{
	return *_address;
}

TEST_GROUP(MemoryIO)
{
};

TEST(MemoryIO, writeDataShouldWriteTheDataToIntendedAddress)
{
	int fakeRegister;
	setAddress(&fakeRegister);
	setData(0xAA55AA55);
	writeData();
	LONGS_EQUAL(0xAA55AA55, fakeRegister);
	LONGS_EQUAL(0xAA55AA55, readData());

}