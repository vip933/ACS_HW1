#include "tetrahedron.h"

//------------------------------------------------------------------------------
// Ввод параметров тетраэдра из файла
void InTetrahedron(tetrahedron &tetrahedron, FILE *file) {
    fscanf(file, "%d", &tetrahedron.edge);
    fscanf(file, "%lf", &tetrahedron.density);
}

//------------------------------------------------------------------------------
// Случайный ввод параметров тетраэдра
void InRndTetrahedron(tetrahedron &tetrahedron) {
    tetrahedron.edge = Random();
    tetrahedron.density = RandomDensity();
}

//------------------------------------------------------------------------------
// Вывод параметров тетраэдра в файловый поток
void OutTetrahedron(tetrahedron &tetrahedron, FILE *file) {
    fprintf(file, "It's a tetrahedron: edge = %d, density = %.2f surface square = %.2f\n",
            tetrahedron.edge,
            tetrahedron.density,
            Square(tetrahedron)
    );
}

//------------------------------------------------------------------------------
// Вычисление площади поверхности тетраэдра
double Square(tetrahedron &tetrahedron) {
    return tetrahedron.edge * tetrahedron.edge * SQUARE_ROOT_OF_3;
}