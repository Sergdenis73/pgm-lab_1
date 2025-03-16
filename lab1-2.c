#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() 
{
    int N;
    printf("Введіть кількість чисел: ");
    scanf("%d", &N);

    // Динамічне виділення пам'яті для масиву
    int *MAS = (int *)malloc(N * sizeof(int));
    if (MAS == NULL) {
        printf("Помилка виділення пам'яті!\n");
        return 1;
    }

    printf("Введіть %d цілих чисел:\n", N);
    for (int i = 0; i < N; i += 1) {
        scanf("%d", &MAS[i]);
    }

    int sum_even = 0, count_even = 0;
    long long product_odd = 1;
    int count_odd = 0;
    int max_value = MAS[0], max_index = 0;

    for (int i = 0; i < N; i += 1) {
        if (MAS[i] % 2 == 0) {  // Парні числа
            sum_even += MAS[i];
            count_even+=1;
        } else {  // Непарні числа
            product_odd *= MAS[i];
            count_odd+=1;
        }

        if (MAS[i] > max_value) {
            max_value = MAS[i];
            max_index = i;
        }
    }

    double avg_even = (count_even > 0) ? (double)sum_even / count_even : 0;
    double geom_mean_odd = (count_odd > 0) ? pow((double)product_odd, 1.0 / count_odd) : 0;

    printf("Сума парних чисел: %d\n", sum_even);
    printf("Середнє арифметичне парних чисел: %.2f\n", avg_even);
    printf("Добуток непарних чисел: %lld\n", product_odd);
    printf("Середнє геометричне непарних чисел: %.2f\n", geom_mean_odd);
    printf("Максимальне значення: %d, його номер у масиві: %d\n", max_value, max_index + 1);

    // Звільнення пам'яті
    free(MAS);

    return 0;
}