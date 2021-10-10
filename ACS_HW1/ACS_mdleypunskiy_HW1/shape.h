#ifndef __shape__
#define __shape__

//------------------------------------------------------------------------------
// shape.h - содержит описание обобщающей геометрической фигуры,
//------------------------------------------------------------------------------

#include <stdio.h>
#include "ball.h"
#include "parallelepiped.h"
#include "tetrahedron.h"

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
struct shape {
    // значения ключей для каждой из фигур
    enum key {BALL, PARALLELEPIPED, TETRAHEDRON};
    key k; // ключ
    // используемые альтернативы
    union { // используем простейшую реализацию
        ball ball;
        parallelepiped parallelepiped;
        tetrahedron tetrahedron;
    };
};

// Ввод параметров обобщенной из файла
bool InShape(FILE *file, shape &shape);

// Случайный ввод обобщенной фигуры
bool InRndShape(shape& shape);

// Вывод параметров обобщенной фигуры в файловый поток
void OutShape(shape &shape, FILE *file);

// Вычисление площади поверхности обобщенной фигуры
double Square(shape &shape);

#endif
