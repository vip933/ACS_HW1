#ifndef __tetrahedron__
#define __tetrahedron__

#include <stdio.h>
#include "rnd.h"

//------------------------------------------------------------------------------
// tetrahedron.h - содержит описание тетраэдра
//------------------------------------------------------------------------------

struct tetrahedron {
    int edge;
    double density;
};

const double SQUARE_ROOT_OF_3 = 1.73205;

// Ввод параметров тетраэдра из файла
void InTetrahedron(tetrahedron &tetrahedron, FILE *file);

// Случайный ввод параметров тетраэдра
void InRndTetrahedron(tetrahedron &tetrahedron);

// Вывод параметров тетраэдра в форматируемый поток
void OutTetrahedron(tetrahedron &tetrahedron, FILE *file);

// Вычисление площади поверхности тетраэдра
double Square(tetrahedron &tetrahedron);

#endif
