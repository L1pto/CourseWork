#include "DecimalString.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;


DecimalString::DecimalString( int source)//конструктор без параметров
{
	length = source;
	char_pointer = new char[length + 1];
	if (source == 0) char_pointer[0] = '\0';
	cout << "DecimalString(int) done!" << endl;
}

DecimalString::DecimalString( char source)//конструктор, принимающий в качестве параметра символ
{
	if (char_pointer[0] >= '0'&&char_pointer[0] <= '9')
	{
		cout << "DecimalString(char_pointer ch)" << endl;
	}
	else
	{
		cout << "Bad symbol, pCh[0]= " << char_pointer[0] << endl;
		if (char_pointer)
			delete[]char_pointer;
		length = 0;
		char_pointer = new char[length + 1];
		char_pointer[0] = '\0';
		return;
	}

}

DecimalString::DecimalString(const char* source): Base_String(source)//конструктор, принимающий в качестве параметра Си-строку
{
	if ((char_pointer[0] > '0'&& char_pointer[0]>'9') && (char_pointer[0] != '-'&&char_pointer[0] != '+'))
	{
		cout << "Bad symbol, pCh[0]= " << char_pointer[0] << endl;
		if (char_pointer)
			delete[]char_pointer;
		length = 0;
		char_pointer = new char[length + 1];
		char_pointer[0] = '\0';
		number = 1;
		return;
	}
	for (int i = 1; i < length; i++)
	{
		if (char_pointer[i] >= '0' && char_pointer[i] <= '9')
		{
			continue;
			number = 0;
		}
		else
		{
			cout << "Bad Stroka,pCh[" << i << "]" << char_pointer[i] << endl;
			if (char_pointer)
				delete[]char_pointer;
			length = 0;
			char_pointer = new char[length + 1];
			char_pointer[0] = '\0';
			number = 1;
			return;
		}
	}

}

DecimalString::DecimalString(const DecimalString& source): 
Base_String(source.char_pointer)// конструктор копирования
{ }

DecimalString& DecimalString::operator=(const DecimalString& source)//перегрузка оператора присваивания
{
	if (&source != this)
	{
		delete[] char_pointer;
		length = strlen(source.char_pointer);
		char_pointer = new char[length + 1];
		strcpy_s(char_pointer, length + 1, source.char_pointer);
	}
	cout << "Operator = done!" << endl;
	return *this;

}

DecimalString operator+( const DecimalString&obj1, const DecimalString&obj2)//перезагрузка арифметической суммы строк
{
	int num1 = atoi(obj1.GetStr());
	int num2 = atoi(obj2.GetStr());
	int size;
	if (obj1.length >= obj2.length)
		size = obj1.length + 3;
	else
		size = obj2.length + 3;
	char* pChTmp = new char[size];
	_itoa_s((num1 + num2), pChTmp,size,10);
	DecimalString tmp(pChTmp);
	if (pChTmp)
		delete[] pChTmp;
	cout << "Operator + done!" << endl;
	return tmp;
}

char DecimalString::GetSign()//функция содержащая информацию о знаке
 {
	if (number == 0) {
		if (char_pointer[0] == '-') {
			sign = '-';
		}
		else {
			sign = '+';
		}
	}
	return sign;
}

void DecimalString::Show()//переопределение функции Show(добавляется информация о знаке)
{
	cout << "Type: DecimalString\n";
	cout << "length = " << length << endl;
	cout << "Text: " << ((char_pointer) ? char_pointer : "") << endl;
	cout << "Sign: " << GetSign() << endl;
}

DecimalString::~DecimalString()//деструктор
{
}
