#include <iostream>
#include <algorithm> // ��� ������� ����������
using namespace std;

int main() {
    const int m = 12; // ����� ������
    int arr[m];

    // ���������� ������ ������������
    cout << "Enter " << m << " integers: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    // ������� ����� ��� �������� ���������� �� ���������
    int descendingArr[m];
    copy(arr, arr + m, descendingArr);

    // ���������� �� ����������
    sort(arr, arr + m);

    // ��������� ������, �������������� �� ����������
    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // ���������� �� ���������
    sort(descendingArr, descendingArr + m, greater<int>());

    // ��������� ������, �������������� �� ���������
    cout << "Array sorted in descending order: ";
    for (int i = 0; i < m; i++) {
        cout << descendingArr[i] << " ";
    }
    cout << endl;

    return 0;
}