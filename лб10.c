#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <locale.h>

// ================= ЗАДАНИЕ 1 =================
double f1(double x) {
    if (x <= 3.0) {
        return x * x - 3.0 * x + 9.0;
    }
    else {
        return 1.0 / (x * x * x + 3.0);
    }
}

double f2(double x) {
    return x * exp(sin(x * x));
}

// ================= ЗАДАНИЕ 2 (Вариант 4) =================
double std_sin(double x) {
    return sin(x);
}

// Вычисление суммы N членов ряда
double sin_n(double x, int N) {
    double sum = 1.0;
    double term = 1.0;
    for (int n = 1; n <= N; n++) {
        term *= -1.0 * x * x / ((2.0 * n) * (2.0 * n + 1.0));
        sum += term;
    }
    return sum * x;
}

// Вычисление с заданной точностью
double sin_eps(double x, double eps) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    while (fabs(term) > eps) {
        term *= -1.0 * x * x / ((2.0 * n) * (2.0 * n + 1.0));
        sum += term;
        n++;
    }
    return sum * x;
}

int main() {

    setlocale(LC_CTYPE, "RUS");

    double x_val;

    // --- Выполнение Задания 1 ---
    printf("=== ЗАДАНИЕ 1 ===\n");
    printf("Введите значение x: ");
    // ИСПОЛЬЗУЕМ scanf_s ВМЕСТО scanf
    scanf_s("%lf", &x_val);

    double v1 = f1(x_val);
    double v2 = f2(x_val);

    printf("F1(x) = %.4lf\n", v1);
    printf("F2(x) = %.4lf\n", v2);
    printf("Произведение: %.4lf\n", v1 * v2);
    printf("Разность квадратов: %.4lf\n", v1 * v1 - v2 * v2);
    printf("Удвоенная сумма: %.4lf\n\n", 2.0 * (v1 + v2));

    // --- Выполнение Задания 2 ---
    printf("=== ЗАДАНИЕ 2 (Вариант 4) ===\n");
    printf("Введите значение x для sin(x): ");
    scanf_s("%lf", &x_val);

    int N;
    double eps;
    printf("Введите количество членов ряда N: ");
    scanf_s("%d", &N);
    printf("Введите точность eps (например, 0.0001): ");
    scanf_s("%lf", &eps);

    printf("\nРезультаты вычисления sin(x):\n");
    printf("1) Стандартная функция: %.6lf\n", std_sin(x_val));
    printf("2) Сумма %d членов ряда: %.6lf\n", N, sin_n(x_val, N));
    printf("3) С точностью %lf: %.6lf\n", eps, sin_eps(x_val, eps));

    return 0;
}