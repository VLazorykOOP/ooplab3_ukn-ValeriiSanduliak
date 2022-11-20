// OOPLab3Tpl.cpp : Цей файл містить є шаблоном для 
// виконання лаб. роботи №3. 
// Він містинь функцію "main" з якої починається та закінчується виконання програми.
//

#include <iostream>

// Ваші файли загловки 
//
#include "Lab3Expaple.h"
using namespace std;




int main()
{
    cout << " Lab #3  !\n";
    char ch = '5';
    do {
   
        MenuTask();
        cout << " >>> ";
        ch = cin.get();

        cin.get();

        switch (ch) {
        case '1': task1();  break;
        case '2': task2();  break;
        case '3': task3();  break;
        case '4': return 0;
        }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '5');

    return 0;

}

