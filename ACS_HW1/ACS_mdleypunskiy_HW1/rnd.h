#ifndef __rnd__
#define __rnd__

#include <stdlib.h>
//------------------------------------------------------------------------------
// rnd.h - содержит генератор случайных чисел
//------------------------------------------------------------------------------

// Случайные целые числа в диапозоне от 1 до 256
inline int Random() {
    return rand() % 256 + 1;
}

// Случайные дробные числа в диапозоне от 0.1 до 10
inline double RandomDensity() {
    const double min = 0.1;
    const double max = 10;
    double f = (double)rand() / RAND_MAX;
    return min + f * (max - min);
}

#endif