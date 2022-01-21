#include "Base_String.h"
#include <iostream>

using namespace std;

Base_String::Base_String(int value)//конструктор без параметров
 {
	length = value;
	char_pointer = new char[length + 1];

	if (value == 0) char_pointer[0] = '\0';
	cout << "Base_String(int) done!" << endl;
}

Base_String::Base_String(char ch) //конструтор принимающий символ
{
	length = 1;
	char_pointer = new char[length + 1];

	char_pointer[0] = ch;
	char_pointer[1] = '\0';
	cout << "Base_Strng(char_pointer) done!" << endl;
}

Base_String::Base_String(const char * S) //конструктор принимающий си-строку
{
	length = strlen(S);
	char_pointer = new char[length + 1];
	strcpy_s(char_pointer, length + 1, S);
	cout << "Base_String(const char_pointer*) done!" << endl;
}

Base_String::Base_String(const Base_String &object)//конструктор копирования

{
	length = strlen(object.char_pointer);
	char_pointer = new char[object.length + 1];
	strcpy_s(char_pointer, object.length + 1, object.char_pointer);
	cout << "Base_String(const Base_String&) done!" << endl;
}

Base_String::~Base_String() //деструктор
{
	if (char_pointer) delete[] char_pointer;
	cout << "~Base_String done!" << endl;
}



void Base_String::Show()//функция выводит длину и значение строки
 {
	cout << "Char pointer = " << char_pointer << endl;
	cout << "String length = " << length << endl;
}

void Base_String::Clear()//функция очистки строки
{
	if (char_pointer)
		delete[] char_pointer;
	length= 0;
	char_pointer = new char[1];
	char_pointer[0] = '\0';
}

void Base_String::Check()//функция проверяет строку на пустоту
{
	if (char_pointer[0] == '\0')
		cout << "String clear" << endl;
}
