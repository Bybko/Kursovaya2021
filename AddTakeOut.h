#pragma once
#include "Shcolniki.h"

void Print_List(int, School*, int = 0, int = 0); //зададим i по умолчанию, понадобится для функции поиска, а CoutNum нужно будет, чтобы вывод шапки не повторялся
void WorkingWithFile(int&, School*&, char*);
void AddNew(School*&, int&, char*);
void Rewrite(School*, int, char*); //Перезапись информации в файл
void Interval(School*, int);
void ForSortAfterChange(School*, int, const char[]);