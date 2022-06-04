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

//Функция сортировки
void Sort(School* List, int num, int mode) //Здесь тоже 2 режима, один сортирует в индексный бинарный файл, а второй просто выводит информацию из готового индексного файла
{
    int ind = 0; // ind - количество индексов в файле
    int SortAct = 0;
    fstream file; //Для записи и чтения одновременно
    int* Index = new int[num]; //Создаём массив с индексами (для индексного файла)
    for (int i = 0; i < num; i++) //Заполняем его индексами
        Index[i] = i + 1;

    Print_List(num, List);
    cout << "По какому полю сортировать?" << endl;
    cout << "1. По ФИО\n2. По полу\n3. По классу\n4. По номеру телефона\n5. По оценкам" << endl;
    SortAct = _getch();
    int i, j, m;
    switch (SortAct)
    {
    case '1':
        system("cls");
        file.open("Sort1.txt", ios::binary);
        file.read((char*)&ind, sizeof(int));
        if (ind == num)
            mode = 2;
        else
            mode = 1;
        if (mode == 1)
        {
            //Используем сортировку выбором
            for (i = 0; i < num; i++)
            {
                for (j = i, m = i; j < num; j++)
                {
                    if (strcmp(List[j].FIO, List[m].FIO) < 0)
                        m = j;
                }
                swap(List[i], List[m]);
                swap(Index[i], Index[m]);
            }
            Print_List(num, List);
        }
        if (mode == 2)
        {
            for (int i = 0; i < num; i++)
            {
                file.read((char*)&Index[i], sizeof(int));
                Print_List(Index[i] + 1, List, Index[i], i);
            }
        }
        break;
    case '2':
        system("cls");
        file.open("Sort2.txt", ios::binary);
        file.read((char*)&ind, sizeof(int));
        if (ind == num)
            mode = 2;
        else
            mode = 1;
        if (mode == 1)
        {
            for (i = 0; i < num; i++)
            {
                for (j = i, m = i; j < num; j++)
                {
                    if (strcmp(List[j].pol, List[m].pol) > 0)
                        m = j;
                }
                swap(List[i], List[m]);
                swap(Index[i], Index[m]);
            }
            Print_List(num, List);
        }
        if (mode == 2)
        {
            for (int i = 0; i < num; i++)
            {
                file.read((char*)&Index[i], sizeof(int));
                Print_List(Index[i] + 1, List, Index[i], i);
            }
        }
        break;
    case '3':
        system("cls");
        file.open("Sort3.txt", ios::binary);
        file.read((char*)&ind, sizeof(int));
        if (ind == num)
            mode = 2;
        else
            mode = 1;
        if (mode == 1)
        {
            for (i = 0; i < num; i++)
            {
                for (j = i, m = i; j < num; j++)
                {
                    if (strcmp(List[j].class_name, List[m].class_name) < 0)
                        m = j;
                }
                swap(List[i], List[m]);
                swap(Index[i], Index[m]);
            }
            Print_List(num, List);
        }
        if (mode == 2)
        {
            for (int i = 0; i < num; i++)
            {
                file.read((char*)&Index[i], sizeof(int));
                Print_List(Index[i] + 1, List, Index[i], i);
            }
        }
        break;
    case '4':
        system("cls");
        file.open("Sort4.txt", ios::binary);
        file.read((char*)&ind, sizeof(int));
        if (ind == num)
            mode = 2;
        else
            mode = 1;
        if (mode == 1)
        {
            for (i = 0; i < num; i++)
            {
                for (j = i, m = i; j < num; j++)
                {
                    if (strcmp(List[j].telephone, List[m].telephone) < 0)
                        m = j;
                }
                swap(List[i], List[m]);
                swap(Index[i], Index[m]);
            }
            Print_List(num, List);
        }
        if (mode == 2)
        {
            for (int i = 0; i < num; i++)
            {
                file.read((char*)&Index[i], sizeof(int));
                Print_List(Index[i] + 1, List, Index[i], i);
            }
        }
        break;
    case '5':
        system("cls");
        cout << "1. Физика\n2. Математика\n3. Русский язык\n4. Русская литература\n5. Средний балл" << endl;
        SortAct = '\0';
        SortAct = _getch();
        system("cls");
        switch (SortAct)
        {
        case '1':
            file.open("Sort51.txt", ios::binary);
            file.read((char*)&ind, sizeof(int));
            if (ind == num)
                mode = 2;
            else
                mode = 1;
            if (mode == 1)
            {
                for (i = 0; i < num; i++)
                {
                    for (j = i, m = i; j < num; j++)
                    {
                        if (List[j].fisic > List[m].fisic)
                            m = j;
                    }
                    swap(List[i], List[m]);
                    swap(Index[i], Index[m]);
                }
                Print_List(num, List);
            }
            if (mode == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    file.read((char*)&Index[i], sizeof(int));
                    Print_List(Index[i] + 1, List, Index[i], i);
                }
            }
            break;
        case '2':
            file.open("Sort52.txt", ios::binary);
            file.read((char*)&ind, sizeof(int));
            if (ind == num)
                mode = 2;
            else
                mode = 1;
            if (mode == 1)
            {
                for (i = 0; i < num; i++)
                {
                    for (j = i, m = i; j < num; j++)
                    {
                        if (List[j].math > List[m].math)
                            m = j;
                    }
                    swap(List[i], List[m]);
                    swap(Index[i], Index[m]);
                }
                Print_List(num, List);
            }
            if (mode == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    file.read((char*)&Index[i], sizeof(int));
                    Print_List(Index[i] + 1, List, Index[i], i);
                }
            }
            break;
        case '3':
            file.open("Sort53.txt", ios::binary);
            file.read((char*)&ind, sizeof(int));
            if (ind == num)
                mode = 2;
            else
                mode = 1;
            if (mode == 1)
            {
                for (i = 0; i < num; i++)
                {
                    for (j = i, m = i; j < num; j++)
                    {
                        if (List[j].rus > List[m].rus)
                            m = j;
                    }
                    swap(List[i], List[m]);
                    swap(Index[i], Index[m]);
                }
                Print_List(num, List);
            }
            if (mode == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    file.read((char*)&Index[i], sizeof(int));
                    Print_List(Index[i] + 1, List, Index[i], i);
                }
            }
            break;
        case '4':
            file.open("Sort54.txt", ios::binary);
            file.read((char*)&ind, sizeof(int));
            if (ind == num)
                mode = 2;
            else
                mode = 1;
            if (mode == 1)
            {
                for (i = 0; i < num; i++)
                {
                    for (j = i, m = i; j < num; j++)
                    {
                        if (List[j].lit > List[m].lit)
                            m = j;
                    }
                    swap(List[i], List[m]);
                    swap(Index[i], Index[m]);
                }
                Print_List(num, List);
            }
            if (mode == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    file.read((char*)&Index[i], sizeof(int));
                    Print_List(Index[i] + 1, List, Index[i], i);
                }
            }
            break;
        case '5':
            file.open("Sort55.txt", ios::binary);
            file.read((char*)&ind, sizeof(int));
            if (ind == num)
                mode = 2;
            else
                mode = 1;
            if (mode == 1)
            {
                for (i = 0; i < num; i++)
                {
                    for (j = i, m = i; j < num; j++)
                    {
                        if (List[j].rat > List[m].rat)
                            m = j;
                    }
                    swap(List[i], List[m]);
                    swap(Index[i], Index[m]);
                }
                Print_List(num, List);
            }
            if (mode == 2)
            {
                for (int i = 0; i < num; i++)
                {
                    file.read((char*)&Index[i], sizeof(int));
                    Print_List(Index[i] + 1, List, Index[i], i);
                }
            }
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

    if (mode == 1)
    {
        file.write((char*)& num, sizeof(int));
        for (int i = 0; i < num; i++) //Записываем индексы в созданный бинарный файл
            file.write((char*)&Index[i], sizeof(int));
    }
    file.close();
    delete[] Index;
}