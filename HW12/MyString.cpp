#include <iostream>
#include "MyString.h"
using namespace std;

MyString::MyString()
{
	this->str = new char[strlen("") + 1];
	this->len = 0;
}
MyString::MyString(const char* cp)
{
	this->str = new char[strlen(cp) + 1];
	strcpy(this->str, cp);
	this->len = strlen(cp);
}
MyString::MyString(const MyString& br)
{
	this->str = new char[strlen(br.str) + 1];
	strcpy(this->str, br.str);
	this->len = br.len;
}
MyString::~MyString()
{
	delete[] this->str;
}
MyString& MyString::operator=(const MyString& br)
{
	if (this == &br) { return *this; }
	delete[] this->str;
	this->str = new char[strlen(br.str) + 1];
	strcpy(this->str, br.str);
}
MyString& MyString::operator+(const MyString& br)
{
	MyString res;
	int i = 0;
	res.str = new char[this->len + br.len + 1];
	for (i = 0; i < this->len; i++)
	{
		res.str[i] = this->str[i];
	}
	for (int j = i; j < this->len + br.len + 1; j++)
	{
		res.str[j] = br.str[j];
	}
}
bool MyString::operator>(const MyString& br)
{
	if (this->len > br.len) return true;
	else return false;
}