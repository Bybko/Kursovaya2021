#include <iostream>
#include <fstream>
#include <windows.h> //Для функции Sleep(), которая считает в тысячных долях секунды и для локализации текста при вводе и выводе из файла
#include <iomanip> //Для setw()
#include <conio.h> //Для _getch()
#include "AddTakeOut.h"
#include "Shcolniki.h"
#include "WorkWithStruct.h"
#include "Sort.h"
// "" кавычки пишутся в директиве препроцесора для поиска файла прямо среди файлов нашего проекте

using namespace std;


void Menu(int, School*&, char*);

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tДобро пожаловать в электронный дневник!" << endl;
    Sleep(3000); //Ожидание 3 секунды

    char source[] = "Shcolniki.txt"; // Имя основного рабочего файла
    int num = 0;
    
    School* List = new School[num]; // Массив структур
    WorkingWithFile(num, List, source); //Считывает исходную информацию с файла
    Menu(num, List, source);
    delete[] List;
    return 0;
}

//Функция меню
void Menu(int num, School* &List, char* source)
{
    char act;
    bool is_working = true;
    do
    {
        system("cls"); // Очищение командной строки
        cout << "Введите номер действия, которое хотите совершить:" << endl;
        cout << "1. Вывести текущий список" << endl;
        cout << "2. Добавить нового ученика в список" << endl;
        cout << "3. Изменить информацию о выбранном ученике" << endl;
        cout << "4. Удалить ученика из списка" << endl;
        cout << "5. Отсортировать список" << endl;
        cout << "6. Провести поиск по выбранному параметру" << endl;
        cout << "7. Средний балл согласно интервалу" << endl;
        cout << "0. Выйти из меню" << endl;
        act = _getch(); //Ввод символа в переменную без вывода этого процесса на консоль
        switch (act)
        {
        case '1':
            system("cls");
            Print_List(num, List);
            system("pause"); //Для приостановки работы программы и при необходимости продолжить нужно будет нажать любую кнопку
            break;
        case '2':
            system("cls");
            AddNew(List, num, source);
            system("pause");
            break;
        case '3':
            system("cls");
            ChangeInfo(List, num, source);
            system("pause");
            break;
        case '4':
            system("cls");
            Delete(List, num, source);
            system("pause");
            break;
        case '5':
            system("cls");
            Sort(List, num);
            WorkingWithFile(num, List, source); //Чтобы информация вернулась в исходное положение после сортировки
            system("pause");
            break;
        case '6':
            system("cls");
            Search(List, num);
            system("pause");
            break;
        case '7':
            system("cls");
            Interval(List, num);
            system("pause");
            break;
        case '0':
            is_working = false;
            break;
        default:
            system("cls");
            cout << "Выбран неверный номер действия!" << endl;
            system("pause");
            break;
        }
    } while (is_working);
}