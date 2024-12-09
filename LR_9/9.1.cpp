#include <iostream>
#include <vector>
#include <cstdlib> // ��� rand � srand
#include <ctime>   // ��� time
using namespace std;

int main() {
    // ��������� ����������� ������
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The array size must be greater than 0." << endl;
        return 1;
    }

    vector<int> arr(n);
    srand(time(0)); // ����������� ���������� ���������� �����

    cout << "Generated array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 - 50; // ��������� ����� � ������� [-50, 49]
        cout << arr[i] << " ";
    }
    cout << endl;

    // ����������� ������� ���������� � ���������� ��������
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // ����� ������ ���������� � ���������� ��������
    swap(arr[maxIndex], arr[minIndex]);

    // ��������� �������������� ������
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}