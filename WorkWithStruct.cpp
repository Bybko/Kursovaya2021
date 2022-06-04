#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "WorkWithStruct.h"
#include "Shcolniki.h"
#include "AddTakeOut.h"
#include "Sort.h"

using namespace std;

//Функция поиска
void Search(School* List, int &num, int mode) //mode = 1 это поиск с последущим выводом на экран, mode = 2 нужен исключительно для удаления
{
    char Searching[50] = { '\0' };
    int SearchRate = 0;
    bool Similarity = true; //Проверяет схожесть введёной информации с уже имеющейся в структуре
    int CoutNum = 0; //Подсчитывает количество результатов поиска
    cout << "Укажите номер нужного поля: " << endl;
    cout << "1. ФИО\n2. Пол\n3. Класс\n4. Номер телефона\n5. Оценки по физике\n6. Математике\n7. Русскому\n8. Литературе" << endl;
    char SearchAct = _getch();
    system("cls");
    cout << "Введите информацию: " << endl;
    switch (SearchAct)
    {
    case '1':
        cin.getline(Searching, 20);
        for (int i = 0; i < num; i++)
        {
            Similarity = true;
            int j = 0;
            while (Similarity == true && j != 20)
            {
                if (List[i].FIO[j] != Searching[j])
                    Similarity = false;
                j++;
            }
            if (Similarity == true)
            {
                if (mode == 1)
                {
                    Print_List(i + 1, List, i, CoutNum);
                    CoutNum++;
                }
                else if (mode == 2)
                {
                    for (j = i; j < num - 1; j++)
                        swap(List[j], List[j + 1]);
                    num--;
                    i--; //Для того, чтобы не перескочить через нужный элемент, при условии, что несколько искомых элементов идут друг за другом
                }
            }
        }
        break;
    case '2':
        cin.getline(Searching, 10);
        for (int i = 0; i < num; i++)
        {
            Similarity = true;
            int j = 0;
            while (Similarity == true && j != 10)
            {
                if (List[i].pol[j] != Searching[j])
                    Similarity = false;
                j++;
            }
            if (Similarity == true)
            {
                if (mode == 1)
                {
                    Print_List(i + 1, List, i, CoutNum);
                    CoutNum++;
                }
                else if (mode == 2)
                {
                    for (int j = i; j < num - 1; j++)
                        swap(List[j], List[j + 1]);
                    num--;
                    i--;
                }
            }
        }
        break;
    case '3':
        cin.getline(Searching, 5);
        for (int i = 0; i < num; i++)
        {
            Similarity = true;
            int j = 0;
            while (Similarity == true && j != 5)
            {
                if (List[i].class_name[j] != Searching[j])
                    Similarity = false;
                j++;
            }
            if (Similarity == true)
            {
                if (mode == 1)
                {
                    Print_List(i + 1, List, i, CoutNum);
                    CoutNum++;
                }
                else if (mode == 2)
                {
                    for (int j = i; j < num - 1; j++)
                        swap(List[j], List[j + 1]);
                    num--;
                    i--;
                }
            }
        }
        break;
    case '4':
        cin.getline(Searching, 20);
        for (int i = 0; i < num; i++)
        {
            Similarity = true;
            int j = 0;
            while (Similarity == true && j != 20)
            {
                if (List[i].telephone[j] != Searching[j])
                    Similarity = false;
                j++;
            }
            if (Similarity == true)
            {
                if (mode == 1)
                {
                    Print_List(i + 1, List, i, CoutNum);
                    CoutNum++;
                }
                else if (mode == 2)
                {
                    for (int j = i; j < num - 1; j++)
                        swap(List[j], List[j + 1]);
                    num--;
                    i--;
                }
            }
        }
        break;
    case '5':
        cin >> SearchRate;
        cin.ignore();
        for (int i = 0; i < num; i++)
        {
            if (List[i].fisic == SearchRate)
            {
                if (mode == 1)
                {
                    Print_List(i + 1, List, i, CoutNum);
                    CoutNum++;
                }
                else if (mode == 2)
                {
                    for (int j = i; j < num - 1; j++)
                        swap(List[j], List[j + 1]);
                    num--;
                    i--;
                }
            }
        }
        break;
    case '6':
        cin >> SearchRate;
        cin.ignore();
        for (int i = 0; i < num; i++)
        {
            if (List[i].math == SearchRate)
            {
                if (mode == 1)
                {
                    Print_List(i + 1, List, i, CoutNum);
                    CoutNum++;
                }
                else if (mode == 2)
                {
                    for (int j = i; j < num - 1; j++)
                        swap(List[j], List[j + 1]);
                    num--;
                    i--;
                }
            }
        }
        break;
    case '7':
        cin >> SearchRate;
        cin.ignore();
        for (int i = 0; i < num; i++)
        {
            if (List[i].rus == SearchRate)
            {
                if (mode == 1)
                {
                    Print_List(i + 1, List, i, CoutNum);
                    CoutNum++;
                }
                else if (mode == 2)
                {
                    for (int j = i; j < num - 1; j++)
                        swap(List[j], List[j + 1]);
                    num--;
                    i--;
                }
            }
        }
        break;
    case '8':
        cin >> SearchRate;
        cin.ignore();
        for (int i = 0; i < num; i++)
        {
            if (List[i].lit == SearchRate)
            {
                if (mode == 1)
                {
                    Print_List(i + 1, List, i, CoutNum);
                    CoutNum++;
                }
                else if (mode == 2)
                {
                    for (int j = i; j < num - 1; j++)
                        swap(List[j], List[j + 1]);
                    num--;
                    i--;
                }
            }
        }
        break;
    default:
        system("cls");
        cout << "Выбран неверный номер поля!" << endl;
        break;
    }
    if (mode == 1)
    {
        if (CoutNum == 0)
            cout << "По вашему запросу ничего не найдено..." << endl;
    }
}

//Функция удаления
void Delete(School* &List, int &num, char* source)
{
    char ActDelete;
    cout << "Удалить ученика по значению поля или по номеру?" << endl;
    cout << "1. Ввести номер ученика, которого необходимо удалить" << endl;
    cout << "2. Удалить по полю" << endl;
    ActDelete = _getch();
    int DeleteID = 0; //Номер записи для удаления
    system("cls");

    if (ActDelete == '1' || ActDelete == '2')
        Print_List(num, List);

    School* Buffer = new School[num];
    for (int i = 0; i < num; i++)
        Buffer[i] = List[i];
    delete[] List;
    switch (ActDelete)
    {
    case '1':
        cout << "Введите номер ученика, информацию о котором вы хотите удалить: ";
        cin >> DeleteID;
        cin.ignore(); //Чтобы избежать ошибок в других пунктах меню

        for (int i = 0; i < num; i++)
        {
            if (i == DeleteID - 1)
            {
                for (int j = i; j < num - 1; j++)
                    swap(Buffer[j], Buffer[j + 1]);
                num--;
            }
        }
        List = new School[num];

        for (int i = 0; i < num; i++)
            List[i] = Buffer[i];
        break;
    case '2':
        Search(Buffer, num, 2);

        List = new School[num];

        for (int i = 0; i < num; i++)
            List[i] = Buffer[i];
        break;
    default:
        cout << "Выбран несуществующий номер действия!" << endl;

        List = new School[num];

        for (int i = 0; i < num; i++)
            List[i] = Buffer[i];
        break;
    }

    delete[] Buffer;

    Rewrite(List, num, source);
}

//Функция изменения информации
void ChangeInfo(School* List, int num, char* source)
{
    cout << "Вы хотите изменить всю запись или только конкретное поле?" << endl;
    cout << "1. Полностью всю запись\n2. Только конкретное поле" << endl;
    char Change = _getch();
    int ChangeInfo = 0;
    char WhatChange; //Нужно будет для изменения конкретного поля
    system("cls");
    switch (Change)
    {
    case '1':
        cout << "Текущий список: " << endl;
        Print_List(num, List);
        cout << "Введите номер строки, которую хотите изменить: ";
        cin >> ChangeInfo;
        cin.ignore();
        if (ChangeInfo < 0 || ChangeInfo > num)
        {
            system("cls");
            cout << "Ошибка: такой строки нет" << endl;
            break;
        }
        system("cls");
        for (int i = 0; i < num; i++)
        {
            if (i == ChangeInfo - 1)
            {
                cout << "Измённая информация о данном ученике:" << endl;
                cout << "ФИО: ";
                cin.getline(List[i].FIO, 50);
                cout << "Пол: ";
                cin.getline(List[i].pol, 10);
                cout << "Класс: ";
                cin.getline(List[i].class_name, 5);
                cout << "Номер телефона: ";
                cin.getline(List[i].telephone, 20);
                cout << "Балл по физике: ";
                cin >> List[i].fisic;
                cout << "Балл по математике: ";
                cin >> List[i].math;
                cout << "Балл по русскому языку: ";
                cin >> List[i].rus;
                cout << "Балл по русской литературе: ";
                cin >> List[i].lit;
                cin.ignore();
            }
        }
        ForSortAfterChange(List, num, "Sort1.txt");
        ForSortAfterChange(List, num, "Sort2.txt");
        ForSortAfterChange(List, num, "Sort3.txt");
        ForSortAfterChange(List, num, "Sort4.txt");
        ForSortAfterChange(List, num, "Sort51.txt");
        ForSortAfterChange(List, num, "Sort52.txt");
        ForSortAfterChange(List, num, "Sort53.txt");
        ForSortAfterChange(List, num, "Sort54.txt");
        ForSortAfterChange(List, num, "Sort55.txt");
        break;
    case '2':
        cout << "Текущий список: " << endl;
        Print_List(num, List);
        cout << "Сначала выберете номер студента, часть информации о котором нужно изменить: ";
        cin >> ChangeInfo;
        cin.ignore();
        if (ChangeInfo < 0 || ChangeInfo > num)
        {
            cout << "Ошибка: такой строки нет" << endl;
            break;
        }
        system("cls");
        cout << "Что именно вы хотите изменить?" << endl;
        cout << "1. ФИО\n2. Пол\n3. Класс\n4. Номер телефона\n5. Оценки" << endl;
        WhatChange = _getch();
        system("cls");
        switch (WhatChange)
        {
        case '1':
            for (int i = 0; i < num; i++)
            {
                if (i == ChangeInfo - 1)
                {
                    cout << "Введите новую информацию об ученике" << endl;
                    cout << "ФИО: ";
                    cin.getline(List[i].FIO, 50);
                }
            }
            ForSortAfterChange(List, num, "Sort1.txt");
            break;
        case '2':
            for (int i = 0; i < num; i++)
            {
                if (i == ChangeInfo - 1)
                {
                    cout << "Введите новую информацию об ученике" << endl;
                    cout << "Пол: ";
                    cin.getline(List[i].pol, 10);
                }
            }
            ForSortAfterChange(List, num, "Sort2.txt");
            break;
        case '3':
            for (int i = 0; i < num; i++)
            {
                if (i == ChangeInfo - 1)
                {
                    cout << "Введите новую информацию об ученике" << endl;
                    cout << "Класс: ";
                    cin.getline(List[i].class_name, 5);
                }
            }
            ForSortAfterChange(List, num, "Sort3.txt");
            break;
        case '4':
            for (int i = 0; i < num; i++)
            {
                if (i == ChangeInfo - 1)
                {
                    cout << "Введите новую информацию об ученике" << endl;
                    cout << "Номер телефона: ";
                    cin.getline(List[i].telephone, 20);
                }
            }
            ForSortAfterChange(List, num, "Sort4.txt");
            break;
        case '5':
            for (int i = 0; i < num; i++)
            {
                if (i == ChangeInfo - 1)
                {
                    cout << "Введите новую информацию об ученике" << endl;
                    cout << "Оценка по физике: ";
                    cin >> List[i].fisic;
                    cout << "Оценка по математике: ";
                    cin >> List[i].math;
                    cout << "Оценка по русскому: ";
                    cin >> List[i].rus;
                    cout << "Оценка по литературе: ";
                    cin >> List[i].lit;
                    cin.ignore();
                }
            }
            ForSortAfterChange(List, num, "Sort51.txt");
            ForSortAfterChange(List, num, "Sort52.txt");
            ForSortAfterChange(List, num, "Sort53.txt");
            ForSortAfterChange(List, num, "Sort54.txt");
            ForSortAfterChange(List, num, "Sort55.txt");
            break;
        default:
            cout << "Выбран неверный номер действия!" << endl;
            break;
        }
        break;
    default:
        cout << "Выбран неверный номер действия!" << endl;
        break;
    }

    Rewrite(List, num, source);
}