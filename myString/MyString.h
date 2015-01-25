#pragma once
class MyString
{
public:
	MyString(void);
	MyString(char *str);
	~MyString(void);

	 char& operator[](int inDex);
	 MyString& operator=(char *str);
	 MyString& operator=(MyString mstr);
	 int size();

	 char* GetString();
private:
	char * m_str;
	int m_len;
};

class CExample
{
public:
	CExample(){};
	CExample(int num) {m_num = num;}

	~CExample(){};

private:
	int m_num;
};

class CExampleEx
{
public:
	CExampleEx(){};
	explicit CExampleEx(int num) {m_num = num;}

	~CExampleEx(){};

private:
	int m_num;
};