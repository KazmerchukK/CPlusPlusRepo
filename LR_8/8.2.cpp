#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Введення масиву
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    if (n <= 0) {
        cout << "The array size must be greater than 0." << endl;
        return 1;
    }

    vector<int> arr(n);
    cout << "Enter " << n << " integers: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Знаходження індексу першого максимального елемента
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }

    // Замінюємо від’ємні елементи на 0 перед першим максимальним елементом
    for (int i = 0; i < maxIndex; i++) {
        if (arr[i] < 0) {
            arr[i] = 0;
        }
    }

    // Виведення результату
    cout << "Modified array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}