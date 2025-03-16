#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    system("chcp 65001");
    int N;
    printf("Введіть кількість елементів масиву: ");
    scanf("%d", &N);

    // Динамічне виділення пам'яті для масиву
    double *arr = (double *)malloc(N * sizeof(double));
    if (arr == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    printf("Введіть елементи масиву:\n");
    for (int i = 0; i < N; i+=1) {
        scanf("%lf", &arr[i]);
    }

    // Знаходження максимального за модулем елемента масиву
    double max_abs = fabs(arr[0]);
    for (int i = 1; i < N; i+=1) {
        if (fabs(arr[i]) > max_abs) {
            max_abs = fabs(arr[i]);
        }
    }
    printf("Максимальний за модулем елемент масиву: %.2lf\n", max_abs);

    // Знаходження суми елементів між першим і другим додатними елементами
    int first_positive = -1, second_positive = -1;
    double sum = 0.0;

    for (int i = 0; i < N; i++) {
        if (arr[i] > 0) {
            if (first_positive == -1) {
                first_positive = i;
            } else if (second_positive == -1) {
                second_positive = i;
                break;
            }
        }
    }

    if (first_positive != -1 && second_positive != -1) {
        for (int i = first_positive + 1; i < second_positive; i+=1) {
            sum += arr[i];
        }
        printf("Сума елементів між першим і другим додатними елементами: %.2lf\n", sum);
    } else {
        printf("У масиві недостатньо додатніх елементів для обчислення суми.\n");
    }

    // Звільнення виділеної пам'яті
    free(arr);

    return 0;
}