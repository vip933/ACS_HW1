#include "ball.h"

//------------------------------------------------------------------------------
// Ввод параметров шара из файла
void InBall(ball &ball, FILE *file) {
    fscanf(file, "%d", &ball.radius);
    fscanf(file, "%lf", &ball.density);
}

//------------------------------------------------------------------------------
// Случайный ввод параметров шара
// Проверки не нужны, тк подходит любой радиус, >= 1
void InRndBall(ball &ball) {
    ball.radius = Random();
    ball.density = RandomDensity();
}

//------------------------------------------------------------------------------
// Вывод параметров шара в файловый поток
void OutBall(ball &ball, FILE *file) {
    fprintf(file, "It's a ball: raduis = %d, density = %.2f, surface area = %.2f\n",
            ball.radius,
            ball.density,
            Square(ball)
            );
}

//------------------------------------------------------------------------------
// Получение площади поверхности шара
double Square(ball &ball) {
    return 4 * PI * ball.radius * ball.radius;
}
