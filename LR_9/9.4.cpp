#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 10; // Розмір масиву
    int array[size];

    // Ініціалізація генератора випадкових чисел
    srand(time(NULL));

    // Заповнення масиву випадковими значеннями від 0 до 99
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    // Вивід масиву
    printf("Масив: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Пошук першого нульового елемента
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            printf("Номер першого нульового елемента: %d\n", i);
            return 0;
        }
    }

    // Якщо не знайдено нульових елементів
    printf("Масив не містить нульових елементів.\n");
    return 0;
}
