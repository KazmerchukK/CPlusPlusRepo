#include <iostream>
#include <vector>
#include <cstdlib> // Для rand і srand
#include <ctime>   // Для time
using namespace std;

int main() {
    // Генерація випадкового масиву
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The array size must be greater than 0." << endl;
        return 1;
    }

    vector<int> arr(n);
    srand(time(0)); // Ініціалізація генератора випадкових чисел

    cout << "Generated array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 - 50; // Генерація чисел у діапазоні [-50, 49]
        cout << arr[i] << " ";
    }
    cout << endl;

    // Знаходження індексів найбільшого і найменшого елементів
    int maxIndex = 0, minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Заміна місцями найбільшого і найменшого елементів
    swap(arr[maxIndex], arr[minIndex]);

    // Виведення модифікованого масиву
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}