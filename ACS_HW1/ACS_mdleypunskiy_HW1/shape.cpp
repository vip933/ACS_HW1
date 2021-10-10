//------------------------------------------------------------------------------
// shape.cpp - содержит процедуры связанные с обработкой обобщенной фигуры
// и создания произвольной фигуры
//------------------------------------------------------------------------------

#include <stdlib.h>
#include "shape.h"

//------------------------------------------------------------------------------
// Ввод параметров обобщенной фигуры из файла
bool InShape(FILE *file, shape &s) {
    int k;
    fscanf(file, "%d", &k);
    switch(k) {
        case 1:
            s.k = shape::BALL;
            InBall(s.ball, file);
            return true;
        case 2:
            s.k = shape::PARALLELEPIPED;
            InParallelepiped(s.parallelepiped, file);
            return true;
        case 3:
            s.k = shape::TETRAHEDRON;
            InTetrahedron(s.tetrahedron, file);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Случайный генерация обобщенной фигуры
bool InRndShape(shape& shape) {
    int random_figure = rand() % 3 + 1;
    switch(random_figure) {
        case 1:
            shape.k = shape::BALL;
            InRndBall(shape.ball);
            return true;
        case 2:
            shape.k = shape::PARALLELEPIPED;
            InRndParallelepiped(shape.parallelepiped);
            return true;
        case 3:
            shape.k = shape::TETRAHEDRON;
            InRndTetrahedron(shape.tetrahedron);
            return true;
        default:
            return false;
    }
}

//------------------------------------------------------------------------------
// Вывод параметров текущей фигуры в файловый поток
void OutShape(shape &shape, FILE *file) {
    switch(shape.k) {
        case shape::BALL:
            OutBall(shape.ball, file);
            break;
        case shape::PARALLELEPIPED:
            OutParallelepiped(shape.parallelepiped, file);
            break;
        case shape::TETRAHEDRON:
            OutTetrahedron(shape.tetrahedron, file);
            break;
        default:
            fprintf(file, "%s", "Incorrect figure!\n");
            break;
    }
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности обобщенной фигуры
double Square(shape &shape) {
    switch(shape.k) {
        case shape::BALL:
            return Square(shape.ball);
        case shape::PARALLELEPIPED:
            return Square(shape.parallelepiped);
        case shape::TETRAHEDRON:
            return Square(shape.tetrahedron);
        default:
            return 0.0;
    }
}