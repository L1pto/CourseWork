#define _CRT_SECURE_NO_WARNINGS
#include "IDString.h"
#include <string.h>
#include <iostream>

using namespace std;

IDString::IDString(int value) :Base_String(value)//конструктор без параметров
 {
	length = 0;
	char_pointer = new char[1];
	*char_pointer = 0;
	cout << "StringID(int val)" << endl;
}

IDString::IDString(char ch) : Base_String(ch)//конструктор, принимающий в качестве параметра символ
{
	if ((char_pointer[0] >= 'a' && char_pointer[0] <= 'z') || (char_pointer[0] >= 'A' && char_pointer[0] <= 'Z') || (char_pointer[0] == '_')) {
		cout << "StringID(char_pointer ch)" << endl;
	}
	else {
		if (char_pointer) delete[] char_pointer;
		length = 0;
		char_pointer = new char[length + 1];
		char_pointer[0] = '\0';
		cout << "Bad symbol!" << "char_pointer = " << char_pointer << endl;
	}
}

IDString::IDString(const char* S) : Base_String(S)//конструктор, принимающий в качестве параметра си-строку
{
if ((char_pointer[0] >= '0'&& char_pointer[0] <= '9') || (char_pointer[0] == ' '))
	{
		cout << "Bad Symbol, char_pointer[0]= " << char_pointer[0] << endl;
		if (char_pointer)delete[]char_pointer;
		length = 0;
		char_pointer = new char[length + 1];
		char_pointer[0] = '\0';
		return;
	}
	for (int i = 0; i < length; i++) 
{
		if (((char_pointer[i] >= 'a' && char_pointer[i] <= 'z') || (char_pointer[i] >= 'A' && char_pointer[i] <= 'Z') || (char_pointer[i] >= '0' && char_pointer[i] <= '9')) && (char_pointer[i] != '_'))
		{
			continue;
		}
		else {
			cout << "Bad Stroka,char_pointer[" << i << "]" << char_pointer[i] << endl;
			if (char_pointer)delete[]char_pointer;
			length = 0;
			char_pointer = new char[length + 1];
			char_pointer[0] = '\0';
			return;
		}
	}

IDString::IDString(const IDString &from) : Base_String(from) {  }//конструктор копирования

IDString::~IDString() {
	cout << "~IDString()" << endl;
}

IDString & IDString :: operator = (const IDString &S)//перезагрузка оператора присваивания
{
	if (&S != this) {
		delete[] char_pointer;
		length = strlen(S.char_pointer);
		char_pointer = new char[length + 1];
		strcpy_s(char_pointer, length + 1, S.char_pointer);
	}
	cout << "IDString::operator = (const IDString &S)" << endl;
	return*this;
}

char &IDString::operator [] (int index)//перегрузка операции индексное выражения
{
	if ((index >= 0) && (index < length)) {
		return char_pointer[index];
	}
	cout << "Operator [] done!" << endl;
	return char_pointer[0];
}

IDString IDString::operator+(const IDString&s) const//перегрузка операции конкатенации
{ 
	IDString result;
	delete[] result.char_pointer;
	result.length = length + s.length;
	result.char_pointer = new char[result.length + 1];
	strcpy(result.char_pointer, char_pointer);
	strcat(result.char_pointer + length, s.char_pointer);
	cout << "Operator + done!" << endl;
	return result;
}

void IDString::getUp()//функция переводит  все символы строки (кроме цифр) в верхний регистр
{
	for (int i = 0; i < length; i++)
	{
		if (char_pointer[i] >= 'a' && char_pointer[i] <= 'z')
		{
			int temp = 0;
			temp = (int)char_pointer[i] - 32;
			char_pointer[i] = (char)temp;
		}
	}
}
