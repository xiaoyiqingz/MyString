#include "MyString.h"
#include <string.h>
#include <assert.h>
#include <iostream>

MyString g_str;

//the param is const, e.g./*const MyString& A,*/
//in this func, you must use the const member func of MyString
//to ensure you can't change the member valiable of MyString
const MyString& operator+(const MyString& A, const MyString& B)
{
	int nSize= A.size() + B.size() + 1;  /*size() must be const*/
	char* tmp = new char[nSize];
	tmp[0] = '\0';
	strcpy_s(tmp, nSize, A.GetString()); /*GetString() must be const*/
	strcat_s(tmp, nSize, B.GetString());
	return MyString(tmp);	
}

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

int MyString::size()const
{
	return m_len;
}

char* MyString::GetString()const
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

	MyString strA("hello");
	MyString strB(" zhangzhe");
	MyString strC;
	strC = strA + strB;

	return 0;
}