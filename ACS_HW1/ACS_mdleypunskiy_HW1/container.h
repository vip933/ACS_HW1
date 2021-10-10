#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит тип данных,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include <stdio.h>
#include "shape.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
struct container {
    int len; // текущая длина
    shape *cont;
};

// Инициализация контейнера
void Init(container &container, shape *arr);

// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &container);

// Ввод содержимого контейнера из указанного потока
void InContainer(container &c, FILE *file);

// Случайный ввод содержимого контейнера
void InRndContainer(container &c, int size);

// Вывод содержимого контейнера в указанный поток
void OutContainer(container &c, FILE *file);

// Поиск среднего значение площадей поверхностей всех фигур
double AverageMean(container &c);

// Перестановка элементов контейнера
void RearrangeContainer(container &c, double average);

#endif
