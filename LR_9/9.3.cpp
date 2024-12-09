#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // ����� ������
#define MAX_VALUE 10 // ����������� �������� ��� �������� ������

int main() {
    int array[SIZE];
    int found = 0; // ���� ��� �������� �������� ��������� ��������

    // ����������� ���������� ���������� �����
    srand(time(NULL));

    // ��������� ������ ���������� �����
    printf("������������ �����: \n");
    for (int i = 0; i < SIZE; i++) {
        array[i] = rand() % (MAX_VALUE + 1) - MAX_VALUE / 2; // ��������� ������� �� -MAX_VALUE/2 �� +MAX_VALUE/2
        printf("%d ", array[i]);
    }
    printf("\n");

    // ����� ������� ��������� ��������
    for (int i = 0; i < SIZE; i++) {
        if (array[i] == 0) {
            printf("������ �������� ������� ����������� �� ������� %d (������ %d).\n", i + 1, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("����� �� ������ �������� ��������.\n");
    }

    return 0;
}
