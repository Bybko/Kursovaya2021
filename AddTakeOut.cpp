#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "AddTakeOut.h"
#include "Shcolniki.h" 
#include "Sort.h"

using namespace std;

//������� ������ ���������� �� �����
void Print_List(int num, School* List, int i, int CoutNum)
{
    if (CoutNum == 0)
    {
        cout << "|" << setw(4) << "�-��" << "| " << setw(27) << "������� ��� ��������" << " | ";
        cout << setw(7) << "���" << " | " << setw(5) << "�����" << " | " << setw(13) << "�������" << " | ";
        cout << setw(7) << "���" << " | " << setw(7) << "�����" << " | " << setw(7) << "���.��" << " | " << setw(7) << "���.���" << " | ";
        cout << setw(7) << "��.����" << " |" << endl;
    }

    for (i; i < num; i++)
    {
        cout << "| " << setw(2) << i+1 << " | ";
        cout << setw(27) << List[i].FIO << " | ";
        cout << setw(7) << List[i].pol << " | ";
        cout << setw(5) << List[i].class_name << " | ";
        cout << setw(13) << List[i].telephone << " | ";
        cout << setw(7) << List[i].fisic << " | ";
        cout << setw(7) << List[i].math << " | ";
        cout << setw(7) << List[i].rus << " | ";
        cout << setw(7) << List[i].lit << " | ";
        cout << setw(7) << List[i].rat << " |" << endl;
    }
}

//������� ������ �� �����
void WorkingWithFile(int &num, School* &List, char* source)
{
    ifstream file;
    file.open(source, ios::binary);
    num = 0;
    file.read((char*)&num, sizeof(int));
    delete[] List;
    List = new School[num];
    for (int i = 0; i < num; i++)
        file.read((char*)&List[i], sizeof(School));
    file.close();
}

//������� ���������� ����� ������
void AddNew(School* &List, int &num, char* source)
{
    cout << "������� ������: " << endl;
    Print_List(num, List);
    int kuda = 0;
    cout << "������� ����� ������, ����� ������� ������� �����: ";
    cin >> kuda;
    cin.ignore();
    system("cls");
    if (kuda < 0 || kuda > num)
        cout << "������: ������ ������ ���" << endl;
    else
    {
        num++;
        School* Buffer = new School[num];
        for (int i = 0, j = 0; i < num - 1 && j < num; i++, j++)
        {
            if (kuda != 0) //���� ������������ ����� �������� ������ � ����� ������, ������ �� ����� ��������� ��������� ������ ������
                Buffer[j] = List[i];
            else
                Buffer[j + 1] = List[i]; //���������� "���������" 0 ������� (���� � ��������� �������� i ����� ��� ����� 1)
            if (kuda - 1 == j || kuda == 0)
            {
                cout << "���������� � ����� ��������:" << endl;
                cout << "���: ";
                cin.getline(Buffer[kuda].FIO, 50);
                cout << "���: ";
                cin.getline(Buffer[kuda].pol, 10);
                cout << "�����: ";
                cin.getline(Buffer[kuda].class_name, 5);
                cout << "����� ��������: ";
                cin.getline(Buffer[kuda].telephone, 20);
                cout << "���� �� ������: ";
                cin >> Buffer[kuda].fisic;
                cout << "���� �� ����������: ";
                cin >> Buffer[kuda].math;
                cout << "���� �� �������� �����: ";
                cin >> Buffer[kuda].rus;
                cout << "���� �� ������� ����������: ";
                cin >> Buffer[kuda].lit;
                cin.ignore(); //����� �������� ������ ��� ��������� ����������
                if (kuda == 0)
                    kuda = -1;//����� ��������� �� ����������� ������� ���������� ����� ������
                j++; //����� �� ������������ ���� ������� � ��������� ��������
            }
        }
        delete[] List;

        List = Buffer;

        Rewrite(List, num, source);
    }
}

//������� ���������� � ����
void Rewrite(School* List, int num, char* source)
{
    ofstream file;
    file.open("Repository.txt");
    if (file.is_open())
    {
        for (int i = 0; i < num; i++)
        {
            if (i == 0)
                file << List[i].FIO << " ";
            else
                file << "\n" << List[i].FIO << " ";
            file << List[i].pol << " ";
            file << List[i].class_name << " ";
            file << List[i].telephone << " ";
            file << List[i].fisic << " ";
            file << List[i].math << " ";
            file << List[i].rus << " ";
            file << List[i].lit << " ";
            List[i].rat = (List[i].fisic + List[i].math + List[i].rus + List[i].lit) / 4.0;
            file << List[i].rat;
        }
        file.close();
    }
    else
        cout << "������ �������� �����!" << endl;

    file.open(source, ios::binary);
    file.write((char*)&num, sizeof(int));
    for (int i = 0; i < num; i++)
        file.write((char*)&List[i], sizeof(School));
    file.close();
}

//������� ������ ���������� �������� ���������
void Interval(School* List, int num)
{
    double FirstPoint = 0.0, SecondPoint = 0.0; //���������� ������ � ������ ����� ���������
    int CoutNum = 0;//������������ �� ������ ���������� �������, �� �������� ����� ������� ������������� ������� ���������
    cout << "���������� ������ �������� �������� �����" << endl;
    cout << "������� ��������� �������� � ���������: ";
    cin >> FirstPoint;
    cout << "������� ������� �������� � ���������: ";
    cin >> SecondPoint;
    cin.ignore();
        
    for (int i = 0; i < num; i++)
    {
        if (List[i].rat >= FirstPoint && List[i].rat <= SecondPoint)
        {
            Print_List(i + 1, List, i, CoutNum);
            CoutNum++;
        }
    }

    cout << "����� ���������� �������, ��������������� ������� ���������: " << CoutNum << endl;
}

//������� ��������� ��������� �������� ������ ����� ��������� ���������� � ���� ������
void ForSortAfterChange(School* List, int num, const char IndexFile[]) //��������� ��������� �������� ���� �������� ����������� ����� ���������, ����� ������� ���������� �� ����� ������ �������
{
    ofstream file;
    file.open(IndexFile, ios::binary);
    num--;
    file.write((char*)&num, sizeof(int));
    file.close();
}