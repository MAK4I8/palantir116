#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Завдання 1 (варіант 915)
void task1(void) {
    double a[20][20];
    int rows, cols, i, j, mode, col;
    double sum, avg, min_avg;

    printf("Введіть кількість рядків і стовпців (1..20): ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || rows > 20 || cols <= 0 || cols > 20) {
        printf("Некоректні розміри матриці\n");
        return;
    }

    printf("1 - з клавіатури, 2 - випадкові числа: ");
    scanf("%d", &mode);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mode == 1) {
                scanf("%lf", &a[i][j]);
            } else {
                a[i][j] = (rand() % 2001 - 1000) / 100.0;
            }
        }
    }

    printf("Початкова матриця:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%8.2f", a[i][j]);
        }
        printf("\n");
    }

    col = 0;
    min_avg = 0;
    for (j = 0; j < cols; j++) {
        sum = 0;
        for (i = 0; i < rows; i++) {
            sum += a[i][j];
        }
        avg = sum / rows;
        if (j == 0 || avg < min_avg) {
            min_avg = avg;
            col = j;
        }
    }

    printf("Стовпець з мінімальним середнім: %d (середнє = %.2f)\n", col + 1, min_avg);
}

// Завдання 2 (варіант 929)
void task2(void) {
    int a[20][20];
    int pos[400], neg[400];
    int rows, cols, i, j, mode;
    int k1 = 0, k2 = 0;

    printf("Введіть кількість рядків і стовпців (1..20): ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || rows > 20 || cols <= 0 || cols > 20) {
        printf("Некоректні розміри матриці\n");
        return;
    }

    printf("1 - з клавіатури, 2 - випадкові числа: ");
    scanf("%d", &mode);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mode == 1) {
                scanf("%d", &a[i][j]);
            } else {
                a[i][j] = rand() % 41 - 20;
            }
        }
    }

    printf("Початкова матриця:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (a[i][j] >= 0) {
                pos[k1++] = a[i][j];
            } else {
                neg[k2++] = a[i][j];
            }
        }
    }

    printf("Позитивні та нульові елементи (%d): ", k1);
    if (k1 == 0) {
        printf("немає");
    } else {
        for (i = 0; i < k1; i++) {
            printf("%d ", pos[i]);
        }
    }
    printf("\n");

    printf("Негативні елементи (%d): ", k2);
    if (k2 == 0) {
        printf("немає");
    } else {
        for (i = 0; i < k2; i++) {
            printf("%d ", neg[i]);
        }
    }
    printf("\n");
}

// Завдання 3 (варіант 955)
void task3(void) {
    int a[20][20];
    int rows, cols, i, j, mode;
    int r1, r2, c1, c2, sum, prod;

    printf("Введіть кількість рядків і стовпців (1..20): ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || rows > 20 || cols <= 0 || cols > 20) {
        printf("Некоректні розміри матриці\n");
        return;
    }

    printf("1 - з клавіатури, 2 - випадкові числа: ");
    scanf("%d", &mode);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mode == 1) {
                scanf("%d", &a[i][j]);
            } else {
                a[i][j] = rand() % 41 - 20;
            }
        }
    }

    printf("Початкова матриця:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }

    if (cols < 3) {
        printf("а) У матриці немає третього стовпця\n");
    } else if (rows < 2) {
        printf("а) У третьому стовпці менше двох елементів\n");
    } else {
        printf("Введіть номери двох рядків для третього стовпця (1..%d): ", rows);
        scanf("%d %d", &r1, &r2);
        if (r1 < 1 || r1 > rows || r2 < 1 || r2 > rows) {
            printf("Невірні номери рядків\n");
        } else {
            sum = a[r1 - 1][2] + a[r2 - 1][2];
            printf("а) Сума елементів %d і %d третього стовпця: %d\n", r1, r2, sum);
        }
    }

    if (rows < 2) {
        printf("б) У матриці немає другого рядка\n");
    } else if (cols < 2) {
        printf("б) У другому рядку менше двох елементів\n");
    } else {
        printf("Введіть номери двох стовпців для другого рядка (1..%d): ", cols);
        scanf("%d %d", &c1, &c2);
        if (c1 < 1 || c1 > cols || c2 < 1 || c2 > cols) {
            printf("Невірні номери стовпців\n");
        } else {
            prod = a[1][c1 - 1] * a[1][c2 - 1];
            printf("б) Добуток елементів %d і %d другого рядка: %d\n", c1, c2, prod);
        }
    }
}

// Завдання 4 (варіант 999)
void task4(void) {
    double a[20][20];
    int rows, cols, i, j, mode, k, row, col;
    double min, max;

    printf("Введіть кількість рядків і стовпців (1..20): ");
    if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || rows > 20 || cols <= 0 || cols > 20) {
        printf("Некоректні розміри матриці\n");
        return;
    }

    printf("1 - з клавіатури, 2 - випадкові числа: ");
    scanf("%d", &mode);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mode == 1) {
                scanf("%lf", &a[i][j]);
            } else {
                a[i][j] = (rand() % 2001 - 1000) / 100.0;
            }
        }
    }

    printf("Початкова матриця:\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%8.2f", a[i][j]);
        }
        printf("\n");
    }

    row = 0;
    col = 0;
    max = 0;
    for (i = 0; i < rows; i++) {
        min = a[i][0];
        k = 0;
        for (j = 1; j < cols; j++) {
            if (a[i][j] < min) {
                min = a[i][j];
                k = j;
            }
        }
        if (i == 0 || min > max) {
            max = min;
            row = i;
            col = k;
        }
    }

    printf("Найбільший серед мінімальних по рядках: %.2f (рядок %d, стовпець %d)\n", max, row + 1, col + 1);
}

// Завдання 5 (варіант 950)
void task5(void) {
    int a[20][20];
    int n, i, j, mode, temp;

    printf("Введіть розмір квадратної матриці n (1..20): ");
    if (scanf("%d", &n) != 1 || n <= 0 || n > 20) {
        printf("Некоректний розмір матриці\n");
        return;
    }

    printf("1 - з клавіатури, 2 - випадкові числа: ");
    scanf("%d", &mode);

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (mode == 1) {
                scanf("%d", &a[i][j]);
            } else {
                a[i][j] = rand() % 41 - 20;
            }
        }
    }

    printf("Початкова матриця:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i < j && i + j < n - 1) {
                temp = a[i][j];
                a[i][j] = a[n - 1 - i][j];
                a[n - 1 - i][j] = temp;
            }
        }
    }

    printf("Після обміну верхньої та нижньої чвертей:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (i > j && i + j < n - 1) {
                temp = a[i][j];
                a[i][j] = a[i][n - 1 - j];
                a[i][n - 1 - j] = temp;
            }
        }
    }

    printf("Після обміну правої та лівої чвертей:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%6d", a[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int choice;
    srand((unsigned int)time(NULL));

    while (1) {
        printf("\n1 - Завдання 1\n");
        printf("2 - Завдання 2\n");
        printf("3 - Завдання 3\n");
        printf("4 - Завдання 4\n");
        printf("5 - Завдання 5\n");
        printf("0 - Вихід\n");
        printf("Ваш вибір: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3();
                break;
            case 4:
                task4();
                break;
            case 5:
                task5();
                break;
            case 0:
                return 0;
            default:
                printf("Невірний пункт меню\n");
        }
    }

    return 0;
}
