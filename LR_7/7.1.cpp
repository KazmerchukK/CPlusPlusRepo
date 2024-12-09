#include <iostream>
using namespace std;

int main() {
    int c0;

    // �������� ����������� �������� c0
    cout << "Enter a natural number: ";
    cin >> c0;

    // �������� �� ���������� ��������� �����
    if (c0 <= 0) {
        cout << "The number must be a natural number (greater than 0)." << endl;
        return 1;
    }

    int steps = 0;

    // �������� ����, �� ������ ������� ��������
    while (c0 != 1) {
        cout << c0 << " ";
        if (c0 % 2 == 0) {
            c0 /= 2;
        }
        else {
            c0 = 3 * c0 + 1;
        }
        steps++;
    }

    // ��������� ���������� �������� (1) � ������� �����
    cout << c0 << endl;
    cout << "steps = " << steps << endl;

    return 0;
}