#pragma once

class MyString;
const MyString& operator+(const MyString& A, const MyString& B);

class MyString
{
public:
	MyString(void);
	MyString(char *str);
	~MyString(void);

	 char& operator[](int inDex);
	 MyString& operator=(char *str);
	 MyString& operator=(MyString mstr); 
	 friend const MyString& operator+(const MyString& A, const MyString& B);
	 
	 int size() const;

	 char* GetString() const; 
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

public:
	void	SetName(const MyString& strText);
	void	SetNameEx(MyString& strText);

private:
	int m_num;
	MyString m_strName;
};

class CExampleEx
{
public:
	CExampleEx(){};
	explicit CExampleEx(int num) {m_num = num;}

	~CExampleEx(){};

private:
	int m_num;
	static int m_Age;
	//static int m_Age = 0;  error;
};