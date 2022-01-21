#include <iostream>
#include <string.h>
#include "Base_String.h"
#include "IDString.h"
#include "DecimalString.h"

using namespace std;

int main()
{
    int a;
    while (true)
    {
        cout << "Choose which class do you want to test:" << endl;
        cout << "You will see (argue)(type)" << endl;
        cout << "1.Base_String" << endl;
        cout << "2.IDString" << endl;
        cout << "3.DecimalString" << endl;
        cout << "4.Testing Base_String with use pointer" << endl;
        cout << "5.Testing IDString with use pointer" << endl;
        cout << "6.Testing DecimalString with use pointer" << endl;
        cout << "Enter '0' to finish testing prog" << endl;
        cin >> a;
        switch (a)
        {
        case 0:
            cout << "Programm is end" << endl;
            exit(0);
        case 1:
        {
            cout << "Create Base_String objects" << endl;
            Base_String obj2('K');
            cout << "Obj2: (K)(char) " << endl;
            obj2.Show();
            Base_String obj3("STROKA");
            cout << "Obj3: (STROKA)(char*) " << endl;
            obj3.Show();
            Base_String obj4 = obj3;
            cout << "Obj4: obj4 oper=obj3 " << endl;
            obj4.Show();
            cout << "Obj4: Clear" << endl;
            obj4.Clear();
            obj4.Show();
            Base_String obj5("");
            cout << "Obj5: Check" << endl;
            obj5.Check();
            obj5.Show();
            Base_String obj6(obj3);
            cout << "Obj6: constructor copy obj6(obj3)" << endl;
            obj6.Show();
            break;
        }
        case 2:
        {
            cout << "Create IDString objects" << endl;
            IDString obj6('I');
            cout << "-Good obj6: (I)(char) " << endl;
            obj6.Show();
            cout << "-Bad obj7: (9)(char)" << endl;
            IDString obj7('9');
            obj7.Show();
            cout << "-Bad obj8: (IdentS1r)(char *) " << endl;
            IDString obj8("IdentS1r");
            obj8.Show();
            cout << "-Bad obj82: (1IdentSr)(char *) " << endl;
            IDString obj82("1IdentSr");
            obj82.Show();
            cout << "-Good obj81: (IdentStr)(char *) " << endl;
            IDString obj81("IdentStr");
            obj81.Show();
            cout << "-Bad obj9: (Ident Str)(char *) " << endl;
            IDString obj9("Ident Str");
            obj9.Show();
            IDString obj10 = obj81;
            cout << "-Obj10: obj10 operator = (obj81) " << endl;
            obj10.Show();
            cout << "-Obj11: (idsTRi2ng)(char *) " << endl;
            IDString obj11("idsTRi2ng");
            obj11.getUp();
            obj11.Show();
            cout << "Obj12: constructor copy obj12(obj81)" << endl;
            IDString obj12(obj81);
            obj12.Show();
            cout << "Obj12: obj12= obj81+obj6" << endl;
            obj12 = obj81 + obj6;
            obj12.Show();
            cout << "obj12[3]: " << obj12[3] << endl;

            break;
        }
        case 3:
        {
            cout << "Create DecimalString objects: " << endl;
            cout << "-Good obj13: (3)(char) " << endl;
            DecimalString obj13('3');
            obj13.Show();
            cout << "-Bad obj14: (I)(char) " << endl;
            DecimalString obj14('I');
            obj14.Show();
            cout << "-Good obj15: (+665239)(char *) " << endl;
            DecimalString obj15("+665239");
            obj15.Show();
            cout << "-Bad obj16: (I9831)(char *) " << endl;
            DecimalString obj16("I9831");
            obj16.Show();
            cout << "-Obj17: obj17=obj18 " << endl;
            DecimalString obj17 = obj15;
            obj17.Show();
            cout << "-Obj17: obj17 = obj18(-213) + obj151(3)" << endl;
            DecimalString obj151("3");
            DecimalString obj18("-213");
            obj17 = obj151 + obj18;
            obj17.Show();
            cout << "Obj19: constructor copy obj19(obj17)" << endl;
            DecimalString obj19(obj17);
            obj19.Show();
            break;
        }
        case 4:
        {
            Base_String *stringArray[4]{new Base_String(), new Base_String('k'), new Base_String("STROKA"), new Base_String(*(stringArray[2]))};
            for (int i = 0; i < 4; ++i) //тестирование конструкторов класса СТРОКА
            {
                stringArray[i]->Show();
            }
            cout << "-End of array show" << endl;
            cout << "--operator overloading" << endl;
            *stringArray[3] = *stringArray[1]; //перегрузка оператора присваивания
            stringArray[3]->Show();
            cout << "--test function check the string empty" << endl;
            stringArray[0]->Check(); //тестирование функции проверки строки на пустоту
            for (int i = 0; i < 4; ++i)
            {
                stringArray[i]->Clear(); //тестирование функции Clear
            }
            break;
        }
        case 5:
        {
            IDString *istringArray[6]{new IDString('x'), new IDString('4'), new IDString("string"), new IDString("3itmop"), new IDString("iden6t"), new IDString(*(istringArray[2]))};
            for (int i = 0; i < 6; ++i) //тестирование конструкторов класса СТРОКА_ИНДЕНТИФИКАТОР
            {
                istringArray[i]->Show();
            }
            cout << "-End of array show" << endl;
            cout << "--test function the uppercase" << endl;
            char *l = 0;
            istringArray[4]->getUp(); //тестирование функции перевода символов в верхний регистр кроме цифр
            istringArray[4]->Show();
            cout << "--operator overloading" << endl;
            *istringArray[5] = (*istringArray[2] + *istringArray[4]); //тестирование оператора перегрузки (+) и (=)
            istringArray[5]->Show();
            cout << "--operator overloading [] " << endl;
            *istringArray[5] = (*istringArray[2])[3]; //тестирование оператора перегркузи ([])
            istringArray[5]->Show();
            for (int i = 0; i < 6; ++i)
            {
                istringArray[i]->Clear(); //тестирование функции Clear
            }
            break;
        }
        case 6:
        {
            DecimalString *dstringArray[5]{new DecimalString('x'), new DecimalString('5'), new DecimalString("-746234"), new DecimalString("_923483"), new DecimalString(*(dstringArray[2]))};
            for (int i = 0; i < 5; ++i) //тестирование конструкторов класса ДЕСЯТИЧНАЯ_СТРОКА
            {
                dstringArray[i]->Show();
            }
            cout << "-End of array show" << endl;
            cout << "--operator overloading +" << endl;
            *dstringArray[4] = *dstringArray[2] + *dstringArray[1]; //перегрузка оператора "+"
            dstringArray[4]->Show();
            cout << "--operator overloading = " << endl;
            *dstringArray[4] = *dstringArray[1]; //перегрузка оператора "="
            dstringArray[4]->Show();

            for (int i = 0; i < 5; ++i)
            {
                dstringArray[i]->Clear(); //тестирование функции Clear
            }
            break;
        }
        default:
            cout << "There are no this classes. Try again, please" << endl;
            break;
        }
    }
}
