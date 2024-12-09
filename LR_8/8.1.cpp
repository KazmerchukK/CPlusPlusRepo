#include <iostream>
#include <algorithm> // Для функцій сортування
using namespace std;

int main() {
    const int m = 12; // Розмір масиву
    int arr[m];

    // Заповнення масиву користувачем
    cout << "Enter " << m << " integers: " << endl;
    for (int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    // Копіюємо масив для окремого сортування за спаданням
    int descendingArr[m];
    copy(arr, arr + m, descendingArr);

    // Сортування за зростанням
    sort(arr, arr + m);

    // Виведення масиву, впорядкованого за зростанням
    cout << "Array sorted in ascending order: ";
    for (int i = 0; i < m; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Сортування за спаданням
    sort(descendingArr, descendingArr + m, greater<int>());

    // Виведення масиву, впорядкованого за спаданням
    cout << "Array sorted in descending order: ";
    for (int i = 0; i < m; i++) {
        cout << descendingArr[i] << " ";
    }
    cout << endl;

    return 0;
}