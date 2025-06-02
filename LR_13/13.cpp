#include <iostream>
#include <ctime> // для генер рандом чисел
using namespace std;

int main() {
    srand(time(0)); // ген випад чисел

    const int SIZE = 5;
    int matrix[SIZE][SIZE];

    int *ptr = &matrix[0][0]; //вказівник на перший елемент масиву

    //заповнення випадковими числами та виведення масиву
    cout << "масив:" << endl;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            *(ptr + i * SIZE + j) = rand() % 100; //випадкові значення від 0 до 99
            cout.width(4);
            cout << *(ptr + i * SIZE + j);
        }
        cout << endl;
    }

    cout << "\nГоловна діагональ: ";
    for (int i = 0; i < SIZE; i++) {
        cout << *(ptr + i * SIZE + i) << " ";
    }

    cout << "\n побічна діагональ: ";
    for (int i = 0; i < SIZE; i++) {
        cout << *(ptr + i * SIZE + (SIZE - 1 - i)) << " ";
    }

    int evenCount = 0, oddCount = 0;

    for (int i = 0; i < SIZE * SIZE; i++) {
        if (*(ptr + i) % 2 == 0)
            evenCount++;
        else
            oddCount++;
    }

    cout << "\nК-сть парних елементів: " << evenCount;
    cout << "\nК-сть непарних елементів: " << oddCount << endl;

    return 0;
}