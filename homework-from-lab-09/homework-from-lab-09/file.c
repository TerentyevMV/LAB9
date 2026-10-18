#define _USE_MATH_DEFINES
#define M_PI            3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#define ROW 9
#define COL 9


#include <stdio.h>
#include <locale.h>
#include <math.h>


double task();


int main() {

    // Кодировка
    setlocale(LC_ALL, ".UTF-8");

    task();
    return 0;
}

double task() {
    double a; int b; char c;
    puts("Введите символ, из которого будет строиться фигура: ");
    scanf(" %c", &c);

    puts("Введите угол а в градусах: ");
    scanf(" %lf", &a);

    puts("Введите сторону b: ");
    scanf(" %d", &b);

    double oppositeLen = round(tan(a * M_PI / 180) * b);
    double adjacentLen = b;

    for (int row = 1; row <= oppositeLen; row++)
    {
        double spacesInRow = adjacentLen - (adjacentLen / oppositeLen) * row;
        for (int i = 1; i <= spacesInRow; i++) {
            printf("  ");
        }

        for (int col = 1; col <= ceil(adjacentLen - spacesInRow); col++) {
            printf("%2c", c);
        }

        printf("\n");
    }

    return 0.;
}