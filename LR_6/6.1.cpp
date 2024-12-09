#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "������ ���������� ����� N: ";
    cin >> N;

    // �������� ���� ����� ��� ���������
    int originalN = N;

    // ��������� ������� �����
    int lastDigit = N % 10;

    // ���������� ������� ���� �� ����� �����
    int firstDigit = N;
    int factor = 1;
    while (firstDigit >= 10) {
        firstDigit /= 10;
        factor *= 10;
    }

    // ���� ����� ���������� � ���� �����, �� ������������ �� �������
    if (factor == 1) {
        cout << "����� ���������� � ���� �����: " << originalN << endl;
        return 0;
    }

    // ��������� ����� �� ������� �����
    int middlePart = (N % factor) / 10;

    // ������� ���� ����� � �������������� ������ �� ��������� ������
    int newNumber = lastDigit * factor + middlePart * 10 + firstDigit;

    cout << "����� � �������������� ������ �� ��������� �������: " << newNumber << endl;

    return 0;
}
