#include "MyString.h"
#include <string.h>
#include <assert.h>
#include <iostream>


MyString::MyString(char * str):m_str(str)
{
	m_len = strlen(str);
}

MyString::MyString()
{
}


MyString::~MyString(void)
{
}

char& MyString::operator[](int inDex)
{
	assert(inDex > 0 && inDex < m_len);
	return m_str[inDex];
}

MyString& MyString::operator=(char * str)
{
	m_str = str;
	return *this;
}
MyString& MyString::operator=(MyString mstr)
{
	m_str = mstr.m_str;
	return *this;
}

int MyString::size()
{
	return m_len;
}

char* MyString::GetString()
{
	return m_str;
}

int main()
{
	MyString mstr("abc");
	char c = mstr[2];
	int len = mstr.size();
	std::cout << c << len << std::endl;

	MyString mstr1, mstr2;
	mstr1 = "abcdef";
	mstr2 = mstr1;

	std::cout << mstr1.GetString() << std::endl;
	std::cout << mstr2.GetString() << std::endl;
	
	CExample exm1;
	CExample exm2 = 10;
	CExample exm3(10);

	CExampleEx exmex1;
	//CExampleEx exmex2 = 10;
	CExampleEx exmex3(10);

	return 0;
}