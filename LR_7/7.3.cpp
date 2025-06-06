#include <iostream>
using namespace std;

int main() {
    int n;
    const int MAX_SIZE = 50; // ������������ ����� ��� ����������� ��������

    // ����� �� �������� ������ ��������
    cout << "Enter the side size of the square (greater than 1 and less than or equal to " << MAX_SIZE << "): ";
    cin >> n;

    // �������� ���������� ��������� ������
    if (n <= 1) {
        cout << "The side size must be greater than 1." << endl;
        return 1;
    }

    if (n > MAX_SIZE) {
        cout << "Sorry, the side size is too big." << endl;
        return 1;
    }

    // ������� ���� ��������
    cout << '+';
    for (int i = 0; i < n; i++) {
        cout << '-';
    }
    cout << '+' << endl;

    // ����� ������� ��������
    for (int i = 0; i < n; i++) {
        cout << '|';
        for (int j = 0; j < n; j++) {
            cout << ' ';
        }
        cout << '|' << endl;
    }

    // ������ ���� ��������
    cout << '+';
    for (int i = 0; i < n; i++) {
        cout << '-';
    }
    cout << '+' << endl;

    return 0;
}