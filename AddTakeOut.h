#pragma once
#include "Shcolniki.h"

void Print_List(int, School*, int = 0, int = 0); //������� i �� ���������, ����������� ��� ������� ������, � CoutNum ����� �����, ����� ����� ����� �� ����������
void WorkingWithFile(int&, School*&, char*);
void AddNew(School*&, int&, char*);
void Rewrite(School*, int, char*); //���������� ���������� � ����
void Interval(School*, int);
void ForSortAfterChange(School*, int, const char[]);