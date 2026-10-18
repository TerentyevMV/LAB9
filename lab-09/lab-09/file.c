#define _USE_MATH_DEFINES
#define M_PI            3.14159265358979323846
#define _CRT_SECURE_NO_DEPRECATE
#define ROW 9
#define COL 9


#include <stdio.h>
#include <locale.h>
#include <math.h>


int task1();
int task2();
double task3();

int main() {

	// Кодировка
	setlocale(LC_ALL, ".UTF-8");

	task1();
    task2();
    task3();
	return 0;
}

int task1() {

    int row, col;
    printf("\n");

    // 2

    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL - (9 - row); col++)
            printf("%5d", col * row);

        printf("\n");
    }


    // 3 
    printf("\n\n");

    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL - row; col++)
            printf("%5d", 1);

        printf("\n");
    }

    return 0;
}

int task2() {
    long long num;
    char choice;

    do {
        printf("\nВведите число: ");
        // Считываем как число
        if (scanf("%lld", &num) != 1) {
            printf("Ошибка ввода!\n");
            while (getchar() != '\n');
            continue;
        }

        long long originalNum = num;
        long long tempNum;

        int countDigits = 0;
        int lastDigit = num % 10;

        int c3 = 0, cLast = 0, cEven = 0, cGt5 = 0;
        int sumOdd = 0, sumGe7 = 0;
        long long prodNonZero = 1;
        int sumEvenNoLast = 0;
        int hasDup = 0;
        int sumEvenPlaces = 0, sumOddPlaces = 0;

        int prevDigit = -1;
        int posFromEnd = 1;

        // Первый проход: собираем базовую статистику (справа налево)
        tempNum = num;
        while (tempNum > 0) {
            int digit = tempNum % 10;
            countDigits++;

            if (digit == 3) c3++;
            if (digit == lastDigit) cLast++;
            if (digit % 2 == 0) cEven++;
            if (digit > 5) cGt5++;
            if (digit % 2 != 0) sumOdd += digit;
            if (digit >= 7) sumGe7 += digit;
            if (digit != 0) prodNonZero *= digit;

            // Для 9: сумма четных, кроме последней.
            // Т.к. идем с конца, первая цифра (posFromEnd == 1) - это и есть последняя.
            if (digit % 2 == 0 && posFromEnd != 1) sumEvenNoLast += digit;

            // Для 10: рядом стоящие одинаковые
            if (prevDigit != -1 && digit == prevDigit) hasDup = 1;
            prevDigit = digit;

            // Для 12: суммы разрядов
            if (posFromEnd % 2 == 0) sumEvenPlaces += digit;
            else sumOddPlaces += digit;

            posFromEnd++;
            tempNum /= 10;
        }

        // Второй проход (или математика) для оставшихся пунктов
        long long prodPenultSecond = 0;
        int halfSumEqual = -1; // -1 = нечетная длина

        if (countDigits >= 2) {
            int secondDigit = 0;
            int penultDigit = 0;

            // Ищем вторую цифру (слева) и предпоследнюю
            int posFromLeft = 1;
            tempNum = originalNum;

            // Разворачиваем число математически, чтобы найти вторую цифру
            // (или можно просто поделить на 10 нужное количество раз)
            long long div = 1;
            for (int i = 1; i < countDigits; i++) div *= 10;

            secondDigit = (originalNum / (div / 10)) % 10;
            penultDigit = (originalNum / 10) % 10;

            prodPenultSecond = (long long)secondDigit * penultDigit;

            // Для 11: равна ли сумма половин
            if (countDigits % 2 == 0) {
                int halfLen = countDigits / 2;
                long long halfDiv = 1;
                for (int i = 0; i < halfLen; i++) halfDiv *= 10;

                long long firstHalf = originalNum / halfDiv;
                long long secondHalf = originalNum % halfDiv;

                int sum1 = 0, sum2 = 0;
                while (firstHalf > 0) { sum1 += firstHalf % 10; firstHalf /= 10; }
                while (secondHalf > 0) { sum2 += secondHalf % 10; secondHalf /= 10; }

                halfSumEqual = (sum1 == sum2) ? 1 : 0;
            }
        }

        printf("\n--- РЕЗУЛЬТАТЫ ---\n");
        printf("1) Количество цифр 3: %d\n", c3);
        printf("2) Повторений последней цифры (%d): %d\n", lastDigit, cLast);
        printf("3) Четных цифр: %d\n", cEven);
        printf("4) Цифр > 5: %d\n", cGt5);
        printf("5) Сумма нечетных: %d\n", sumOdd);
        printf("6) Сумма цифр >= 7: %d\n", sumGe7);
        printf("7) Произведение без 0: %lld\n", prodNonZero);

        if (countDigits >= 2) {
            printf("8) Произведение предпоследней и второй: %lld\n", prodPenultSecond);
        }
        else {
            printf("8) Недостаточно цифр.\n");
        }

        printf("9) Сумма четных без последней: %d\n", sumEvenNoLast);

        if (hasDup) printf("10) Рядом стоящие одинаковые: ЕСТЬ\n");
        else printf("10) Рядом стоящие одинаковые: НЕТ\n");

        if (halfSumEqual == -1) printf("11) Нечетная длина.\n");
        else if (halfSumEqual) printf("11) Суммы половин РАВНЫ.\n");
        else printf("11) Суммы половин НЕ РАВНЫ.\n");

        printf("12) Произведение сумм разрядов: %d\n", sumEvenPlaces * sumOddPlaces);

        printf("\nПродолжить? (y - да, n - нет): ");
        while (getchar() != '\n');
        choice = getchar();
        while (getchar() != '\n');

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

double task3() {
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
