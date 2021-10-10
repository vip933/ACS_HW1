#ifndef __parallelepiped__
#define __parallelepiped__

#include <stdio.h>
#include "rnd.h"

using namespace std;

//------------------------------------------------------------------------------
// parallelepiped.h - содержит описание параллелепипеда
//------------------------------------------------------------------------------

struct parallelepiped {
    // ребра
    int edge_a, edge_b, edge_c;
    double density;
};

// Ввод параметров параллелепипеда из файла
void InParallelepiped(parallelepiped &parallelepiped, FILE *file);

// Случайный ввод параметров параллелепипеда
void InRndParallelepiped(parallelepiped &parallelepiped);

// Вывод параметров параллелепипеда в файловый поток
void OutParallelepiped(parallelepiped &parallelepiped, FILE *file);

// Получение площади поверхности параллелепипеда
double Square(parallelepiped &parallelepiped);

#endif