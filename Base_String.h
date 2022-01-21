#pragma once

class Base_String {
protected:
	int length;//указатель на массив символов
	char* char_pointer;// переменная, хранящая длину строки
public:
	Base_String(int = 0);//конструктор без параметров
	Base_String(char);//конструтор принимающий символ
	Base_String(const char*);// конструктор принимающий си-строку
	Base_String(const Base_String&);//конструктор копирования
	~Base_String();//деструктор

	void Show(void);//функция выводит длину и значение строки
	void Clear();//функция очистки строки
	void Check();//функция проверяет строку на пустоту
};
