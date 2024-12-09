#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // Розмір масиву
#define MAX_VALUE 10 // Максимальне значення для елементів масиву

int main() {
    int array[SIZE];
    int found = 0; // Флаг для перевірки наявності нульового елемента

    // Ініціалізація генератора випадкових чисел
    srand(time(NULL));

    // Генерація масиву випадкових чисел
    printf("Згенерований масив: \n");
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % (MAX_VALUE + 1) - MAX_VALUE / 2; // Генерація значень від -MAX_VALUE/2 до +MAX_VALUE/2
        printf("%d ", array[i]);
    }
    printf("\n");

    // Пошук першого нульового елемента
    for (int i = 0; i < SIZE; i++) {
        if (array[i] == 0) {
            printf("Перший нульовий елемент знаходиться на позиції %d (індекс %d).\n", i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Масив не містить нульових елементів.\n");
    }

    return 0;
}
