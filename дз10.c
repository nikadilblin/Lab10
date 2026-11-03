#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
#include <locale.h>

// Функция вывода определения фигуры
void print_definition() {
    printf("\n--- ОПРЕДЕЛЕНИЕ ---\n");
    printf("Прямоугольный треугольник - это треугольник, в котором один угол равен 90 градусам.\n");
    printf("Сторона, противоположная прямому углу, называется гипотенузой.\n");
    printf("Две другие стороны называются катетами.\n");
}

// Функция вычисления площади
float area_triangle(float a, float b) {
    return 0.5f * a * b; // Добавлена буква 'f', чтобы 0.5 считалось как float
}

// Функция вычисления радиуса описанной окружности R (по варианту 4)
float get_radius(float a, float b) {
    // sqrt возвращает double, поэтому явно приводим результат к float
    float c = (float)sqrt(a * a + b * b);
    return c / 2.0f; // 2.0f вместо 2.0
}

// Функция рисования фигуры
void draw_triangle(int a, int b) {
    printf("\n--- РИСУНОК ---\n");
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            // Рисуем границы: левый катет, нижний катет и гипотенузу
            if (j == 0 || i == a - 1 || j == (b - 1) - (b - 1) * i / (a - 1)) {
                printf("*");
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    setlocale(LC_CTYPE, "RUS");
    int choice;
    float a, b;

    do {
        printf("\n================ МЕНЮ ================\n");
        printf("1. Рассчитать площадь\n");
        printf("2. Вывести определение фигуры\n");
        printf("3. Нарисовать фигуру\n");
        printf("4. Вычислить радиус описанной окружности (R)\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);

        // Если выбрана операция, требующая размеров, запрашиваем их
        if (choice == 1 || choice == 3 || choice == 4) {
            printf("Введите длину катета a (целое число): ");
            scanf("%f", &a);
            printf("Введите длину катета b (целое число): ");
            scanf("%f", &b);
        }

        switch (choice) {
        case 1:
            printf("Площадь прямоугольного треугольника: %.2f\n", area_triangle(a, b));
            break;
        case 2:
            print_definition();
            break;
        case 3:
            draw_triangle((int)a, (int)b);
            break;
        case 4:
            printf("Радиус описанной окружности R: %.2f\n", get_radius(a, b));
            break;
        case 0:
            printf("Выход из программы.\n");
            break;
        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }
    } while (choice != 0);

    return 0;
}