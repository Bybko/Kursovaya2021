#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>
#include <conio.h>
#include "AddTakeOut.h"
#include "Shcolniki.h" 
#include "Sort.h"

using namespace std;

//Функция вывода информации на экран
void Print_List(int num, School* List, int i, int CoutNum)
{
    if (CoutNum == 0)
    {
        cout << "|" << setw(4) << "Н-ер" << "| " << setw(27) << "Фамилия Имя Отчество" << " | ";
        cout << setw(7) << "Пол" << " | " << setw(5) << "Класс" << " | " << setw(13) << "Телефон" << " | ";
        cout << setw(7) << "Физ" << " | " << setw(7) << "Матем" << " | " << setw(7) << "Рус.яз" << " | " << setw(7) << "Рус.лит" << " | ";
        cout << setw(7) << "Ср.балл" << " |" << endl;
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

//Функция чтения из файла
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

//Функция добавления новой записи
void AddNew(School* &List, int &num, char* source)
{
    cout << "Текущий список: " << endl;
    Print_List(num, List);
    int kuda = 0;
    cout << "Укажите номер записи, после которой создать новую: ";
    cin >> kuda;
    cin.ignore();
    system("cls");
    if (kuda < 0 || kuda > num)
        cout << "Ошибка: такого номера нет" << endl;
    else
    {
        num++;
        School* Buffer = new School[num];
        for (int i = 0, j = 0; i < num - 1 && j < num; i++, j++)
        {
            if (kuda != 0) //Если пользователь хочет добавить запись в самое начало, значит не нужно заполнять начальную запись другим
                Buffer[j] = List[i];
            else
                Buffer[j + 1] = List[i]; //Записываем "утерянный" 0 элемент (ведь в следующей итерации i будет уже равно 1)
            if (kuda - 1 == j || kuda == 0)
            {
                cout << "Информация о новом студенте:" << endl;
                cout << "ФИО: ";
                cin.getline(Buffer[kuda].FIO, 50);
                cout << "Пол: ";
                cin.getline(Buffer[kuda].pol, 10);
                cout << "Класс: ";
                cin.getline(Buffer[kuda].class_name, 5);
                cout << "Номер телефона: ";
                cin.getline(Buffer[kuda].telephone, 20);
                cout << "Балл по физике: ";
                cin >> Buffer[kuda].fisic;
                cout << "Балл по математике: ";
                cin >> Buffer[kuda].math;
                cout << "Балл по русскому языку: ";
                cin >> Buffer[kuda].rus;
                cout << "Балл по русской литературе: ";
                cin >> Buffer[kuda].lit;
                cin.ignore(); //Чтобы избежать ошибок при повторном добавлении
                if (kuda == 0)
                    kuda = -1;//Чтобы постоянно не срабатывало условие добавления новой записи
                j++; //Чтобы не перезаписать этот элемент в следующее итерации
            }
        }
        delete[] List;

        List = Buffer;

        Rewrite(List, num, source);
    }
}

//Функция перезаписи в файл
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
        cout << "Ошибка открытия файла!" << endl;

    file.open(source, ios::binary);
    file.write((char*)&num, sizeof(int));
    for (int i = 0; i < num; i++)
        file.write((char*)&List[i], sizeof(School));
    file.close();
}

//Функция вывода информации согласно интервалу
void Interval(School* List, int num)
{
    double FirstPoint = 0.0, SecondPoint = 0.0; //Определяет первую и вторую точку интервала
    int CoutNum = 0;//Подсчитывает не только количество выводов, но исколько всего записей удовлетворяют данному интервалу
    cout << "Определите нужный интервал среднего балла" << endl;
    cout << "Введите начальное значение в интервале: ";
    cin >> FirstPoint;
    cout << "Введите крайнее значение в интервале: ";
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

    cout << "Общее количество записей, удовлетворяющих данному интервалу: " << CoutNum << endl;
}

//Функция изменения индексных бинарных файлов после изменения информации в базе данных
void ForSortAfterChange(School* List, int num, const char IndexFile[]) //Заполняет индексный бинарный файл неверной информацией после изменения, чтобы функция сортировки не брала оттуда индексы
{
    ofstream file;
    file.open(IndexFile, ios::binary);
    num--;
    file.write((char*)&num, sizeof(int));
    file.close();
}