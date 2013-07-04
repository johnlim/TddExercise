#include "CppUTest\TestHarness.h"

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