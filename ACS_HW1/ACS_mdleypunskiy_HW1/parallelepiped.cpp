#include "parallelepiped.h"

//------------------------------------------------------------------------------
// Ввод параметров параллелепипеда из файла
void InParallelepiped(parallelepiped &parallelepiped, FILE *file) {
    fscanf(file, "%d", &parallelepiped.edge_a);
    fscanf(file, "%d", &parallelepiped.edge_b);
    fscanf(file, "%d", &parallelepiped.edge_c);
    fscanf(file, "%lf", &parallelepiped.density);
}

//------------------------------------------------------------------------------
// Случайный ввод параметров параллелепипеда
// Проверки не нужны, тк любые 3 стороны задают параллелепипед.
void InRndParallelepiped(parallelepiped &parallelepiped) {
    parallelepiped.edge_a = Random();
    parallelepiped.edge_b = Random();
    parallelepiped.edge_c = Random();
    parallelepiped.density = RandomDensity();
}

//------------------------------------------------------------------------------
// Вывод параметров параллелепипеда в файловый поток
void OutParallelepiped(parallelepiped &parallelepiped, FILE *file) {
    fprintf(file, "It's a parallelepiped: a = %d, b = %d, c = %d, density = %.2f, surface square = %.2f\n",
            parallelepiped.edge_a,
            parallelepiped.edge_b,
            parallelepiped.edge_c,
            parallelepiped.density,
            Square(parallelepiped)
    );
}

//------------------------------------------------------------------------------
// Получение площади поверхности параллелепипеда
double Square(parallelepiped &parallelepiped) {
    return 2 * parallelepiped.edge_a * parallelepiped.edge_b +
           2 * parallelepiped.edge_a * parallelepiped.edge_c +
           2 * parallelepiped.edge_b * parallelepiped.edge_c;
}