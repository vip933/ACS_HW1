//------------------------------------------------------------------------------
// container_Constr.cpp - содержит функции обработки контейнера
//------------------------------------------------------------------------------

#include <stdio.h>
#include <string.h>
#include "container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
void Init(container &container, shape *arr) {
    printf("%s", "Start Init container\n");
    container.cont = arr;
    container.len = 0;
    printf("%s", "End Init container\n");
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void Clear(container &container) {
    container.len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера из указанного потока
void InContainer(container &c, FILE *file) {
    while (!feof(file)) {
        if (InShape(file, c.cont[c.len])) {
            c.len++;
        }
    }
}

//------------------------------------------------------------------------------
// Случайный ввод содержимого контейнера
void InRndContainer(container &c, int size) {
    printf("%s", "Start of init of random figures\n");
    while (c.len < size) {
        if (InRndShape(c.cont[c.len])) {
            c.len++;
        }
    }
    printf("%s", "End of init of random figures\n");
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void OutContainer(container &c, FILE *file) {
    fprintf(file, "%s %d %s", "Container contains", c.len, "elements.\n");
    for (int i = 0; i < c.len; i++) {
        fprintf(file, "%d: ", i);
        OutShape(c.cont[i], file);
    }
}

//------------------------------------------------------------------------------
// Поиск среднего значение площадей поверхностей всех фигур
double AverageMean(container &c) {
    double sum = 0.0;
    for (int i = 0; i < c.len; i++) {
        sum += Square(c.cont[i]);
    }
    return sum / c.len;
}

//------------------------------------------------------------------------------
// Перестановка элементов контейнера
void RearrangeContainer(container &c, double average) {
    int size = c.len + 1;
    shape cpy_array[size];
    int j = 0;
    // Перемещаем все ненужные элементы в начало
    for (int i = 0; i < size; i++) {
        if (Square(c.cont[i]) <= average) {
            cpy_array[j++] = c.cont[i];
        }
    }
    if (j == size || j == 0) {
        return;
    }
    j--;
    // Перемещаем в конец все элементы, площадь которых больше среднего арифметического
    for (int i = 0; i < size; i++) {
        if (Square(c.cont[i]) > average) {
            cpy_array[j++] = c.cont[i];
        }
    }
    // Копируем полученный массив в исходный
    memcpy(c.cont, cpy_array, sizeof(cpy_array));
}