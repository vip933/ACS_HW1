#ifndef __ball__
#define __ball__

#include <stdio.h>
#include "rnd.h"

//------------------------------------------------------------------------------
// ball.h - содержит описание шара
//------------------------------------------------------------------------------

struct ball {
    int radius;
    double density;
};

const double PI = 3.141592;

// Ввод параметров шара из файла
void InBall(ball &ball, FILE *file);

// Случайный ввод параметров шара
void InRndBall(ball &ball);

// Вывод параметров шара в файловый поток
void OutBall(ball &ball, FILE *file);

// Получение площади поверхности шара
double Square(ball &ball);

#endif