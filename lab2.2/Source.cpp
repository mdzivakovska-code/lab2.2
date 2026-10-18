//Source.cpp
#include <iostream>
#include <windows.h>
#include "String.h"

using namespace std;

#pragma pack(push, 1)
class PackedString
{
    char* str;
    int length;
};
#pragma pack(pop)

int main()
{
  
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << " 1. Перевірка конструкторів" << endl;
    String s1;                          
    String s2("Слава Україні");         
    String s3 = s2;                    

    cout << "s1 (за замовчуванням): \"" << s1 << "\"" << endl;
    cout << "s2 (ініціалізація):    \"" << s2 << "\"" << endl;
    cout << "s3 (копія):            \"" << s3 << "\"" << endl;

    cout << " 2. Потокове введення (operator>>) " << endl;
    String sInput;
    cout << "Введіть одне слово: ";
    cin >> sInput;
    cout << "Введене слово: \"" << sInput << "\"" << endl;

    cout << " 3. Операція '+' (конкатенація) " << endl;
    String w1("Дрогобицький ");
    String w2("університет");
    String combined = w1 + w2;
    cout << "\"" << w1 << "\" + \"" << w2 << "\" = \"" << combined << "\"" << endl;

    cout << "\ 4. Операція '-' (видалення підрядка) " << endl;
    String original("Лабораторна робота з програмування");
    String toRemove("робота ");
    String cutResult = original - toRemove;
    cout << "\"" << original << "\" - \"" << toRemove << "\" = \"" << cutResult << "\"" << endl;

    cout << " 5. Операція '*' (пошук підрядка)" << endl;
    String text("Факультет комп'ютерних наук");
    String pattern("наук");
    int pos = text * pattern;
    cout << "Пошук \"" << pattern << "\" у рядку \"" << text << "\"" << endl;
    if (pos != -1)
        cout << "Знайдено на індексі: " << pos << endl;
    else
        cout << "Підрядок відсутній!" << endl;

    cout << "6. Масив об'єктів" << endl;
    const int SIZE = 3;
    String arr[SIZE] = {
        String("Початок"),
        String("Середина"),
        String("Кінець")
    };
    for (int i = 0; i < SIZE; i++)
    {
        cout << "arr[" << i << "] = \"" << arr[i] << "\", довжина = " << arr[i].GetLength() << endl;
    }

    cout << " 7. Розміри класів у пам'яті " << endl;
    cout << "sizeof(MyString) = " << sizeof(String) << " байт" << endl;
    cout << "sizeof(PackedString) [#pragma pack(1)] = " << sizeof(PackedString) << " байт" << endl;

    return 0;
}