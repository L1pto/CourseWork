#pragma once
#include "Base_String.h"

class DecimalString : public Base_String
{
	char sign = 0;//переменная, хранящая знак
	int number=0;//переменная, хранящая информацию о знаке
public:
	DecimalString( int = 0);
	DecimalString(char);// конструктор, принимающий в качестве параметра символ
	DecimalString(const char*);//конструктор, принимающий в качестве параметра Си-строку
	DecimalString(const DecimalString&);//конструктор копирования
	~DecimalString();//деструктор

	DecimalString& operator=(const DecimalString&);// перегрузка оператора присваивания
	friend DecimalString operator+(const DecimalString&,const DecimalString&);//перезагрузка арифметической суммы строк

	char GetSign();//функция содержащая информацию о знаке
	virtual void Show();//переопределение функции Show(добавляется информация о знаке)
	char* GetStr(void) const { return char_pointer; };//функция возвращающая указатель на строку
};