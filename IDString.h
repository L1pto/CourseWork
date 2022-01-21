#pragma once
#include "Base_String.h"

class IDString :public Base_String {
public:
	IDString(int = 0);//конструктор без параметров
	IDString(char);//конструктор, принимающий в качестве параметра символ
	IDString(const char*);//конструктор, принимающий в качестве параметра си-строку
	IDString(const IDString&);//конструктор копирования
	~IDString();//деструктор


	IDString &operator = (const IDString&);//перезагрузка оператора присваивания

	char &operator[] (int);//перегрузка операции индексное выражения
	IDString operator+(const IDString&s) const;//перегрузка операции конкатенации
	void getUp();//функция переводит  все символы строки (кроме цифр) в верхний регистр
};
