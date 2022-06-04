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

//������� ������
void Search(School* List, int &num, int mode) //mode = 1 ��� ����� � ���������� ������� �� �����, mode = 2 ����� ������������� ��� ��������
{
    char Searching[50] = { '\0' };
    int SearchRate = 0;
    bool Similarity = true; //��������� �������� ������� ���������� � ��� ��������� � ���������
    int CoutNum = 0; //������������ ���������� ����������� ������
    cout << "������� ����� ������� ����: " << endl;
    cout << "1. ���\n2. ���\n3. �����\n4. ����� ��������\n5. ������ �� ������\n6. ����������\n7. ��������\n8. ����������" << endl;
    char SearchAct = _getch();
    system("cls");
    cout << "������� ����������: " << endl;
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
                    i--; //��� ����, ����� �� ����������� ����� ������ �������, ��� �������, ��� ��������� ������� ��������� ���� ���� �� ������
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
        cout << "������ �������� ����� ����!" << endl;
        break;
    }
    if (mode == 1)
    {
        if (CoutNum == 0)
            cout << "�� ������ ������� ������ �� �������..." << endl;
    }
}

//������� ��������
void Delete(School* &List, int &num, char* source)
{
    char ActDelete;
    cout << "������� ������� �� �������� ���� ��� �� ������?" << endl;
    cout << "1. ������ ����� �������, �������� ���������� �������" << endl;
    cout << "2. ������� �� ����" << endl;
    ActDelete = _getch();
    int DeleteID = 0; //����� ������ ��� ��������
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
        cout << "������� ����� �������, ���������� � ������� �� ������ �������: ";
        cin >> DeleteID;
        cin.ignore(); //����� �������� ������ � ������ ������� ����

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
        cout << "������ �������������� ����� ��������!" << endl;

        List = new School[num];

        for (int i = 0; i < num; i++)
            List[i] = Buffer[i];
        break;
    }

    delete[] Buffer;

    Rewrite(List, num, source);
}

//������� ��������� ����������
void ChangeInfo(School* List, int num, char* source)
{
    cout << "�� ������ �������� ��� ������ ��� ������ ���������� ����?" << endl;
    cout << "1. ��������� ��� ������\n2. ������ ���������� ����" << endl;
    char Change = _getch();
    int ChangeInfo = 0;
    char WhatChange; //����� ����� ��� ��������� ����������� ����
    system("cls");
    switch (Change)
    {
    case '1':
        cout << "������� ������: " << endl;
        Print_List(num, List);
        cout << "������� ����� ������, ������� ������ ��������: ";
        cin >> ChangeInfo;
        cin.ignore();
        if (ChangeInfo < 0 || ChangeInfo > num)
        {
            system("cls");
            cout << "������: ����� ������ ���" << endl;
            break;
        }
        system("cls");
        for (int i = 0; i < num; i++)
        {
            if (i == ChangeInfo - 1)
            {
                cout << "������� ���������� � ������ �������:" << endl;
                cout << "���: ";
                cin.getline(List[i].FIO, 50);
                cout << "���: ";
                cin.getline(List[i].pol, 10);
                cout << "�����: ";
                cin.getline(List[i].class_name, 5);
                cout << "����� ��������: ";
                cin.getline(List[i].telephone, 20);
                cout << "���� �� ������: ";
                cin >> List[i].fisic;
                cout << "���� �� ����������: ";
                cin >> List[i].math;
                cout << "���� �� �������� �����: ";
                cin >> List[i].rus;
                cout << "���� �� ������� ����������: ";
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
        cout << "������� ������: " << endl;
        Print_List(num, List);
        cout << "������� �������� ����� ��������, ����� ���������� � ������� ����� ��������: ";
        cin >> ChangeInfo;
        cin.ignore();
        if (ChangeInfo < 0 || ChangeInfo > num)
        {
            cout << "������: ����� ������ ���" << endl;
            break;
        }
        system("cls");
        cout << "��� ������ �� ������ ��������?" << endl;
        cout << "1. ���\n2. ���\n3. �����\n4. ����� ��������\n5. ������" << endl;
        WhatChange = _getch();
        system("cls");
        switch (WhatChange)
        {
        case '1':
            for (int i = 0; i < num; i++)
            {
                if (i == ChangeInfo - 1)
                {
                    cout << "������� ����� ���������� �� �������" << endl;
                    cout << "���: ";
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
                    cout << "������� ����� ���������� �� �������" << endl;
                    cout << "���: ";
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
                    cout << "������� ����� ���������� �� �������" << endl;
                    cout << "�����: ";
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
                    cout << "������� ����� ���������� �� �������" << endl;
                    cout << "����� ��������: ";
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
                    cout << "������� ����� ���������� �� �������" << endl;
                    cout << "������ �� ������: ";
                    cin >> List[i].fisic;
                    cout << "������ �� ����������: ";
                    cin >> List[i].math;
                    cout << "������ �� ��������: ";
                    cin >> List[i].rus;
                    cout << "������ �� ����������: ";
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
            cout << "������ �������� ����� ��������!" << endl;
            break;
        }
        break;
    default:
        cout << "������ �������� ����� ��������!" << endl;
        break;
    }

    Rewrite(List, num, source);
}