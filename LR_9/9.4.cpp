#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int size = 10; // ����� ������
    int array[size];

    // ����������� ���������� ���������� �����
    srand(time(NULL));

    // ���������� ������ ����������� ���������� �� 0 �� 99
    for (int i = 0; i < size; i++) {
        array[i] = rand() % 100;
    }

    // ���� ������
    printf("�����: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // ����� ������� ��������� ��������
    for (int i = 0; i < size; i++) {
        if (array[i] == 0) {
            printf("����� ������� ��������� ��������: %d\n", i);
            return 0;
        }
    }

    // ���� �� �������� �������� ��������
    printf("����� �� ������ �������� ��������.\n");
    return 0;
}
