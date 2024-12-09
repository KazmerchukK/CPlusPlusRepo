#include <iostream>
using namespace std;

int main() {
    int n;
    const int MAX_SIZE = 50; // Максимальний розмір для відображення квадрата

    // Запит на введення розміру квадрата
    cout << "Enter the side size of the square (greater than 1 and less than or equal to " << MAX_SIZE << "): ";
    cin >> n;

    // Перевірка коректності введеного розміру
    if (n <= 1) {
        cout << "The side size must be greater than 1." << endl;
        return 1;
    }

    if (n > MAX_SIZE) {
        cout << "Sorry, the side size is too big." << endl;
        return 1;
    }

    // Верхній край квадрата
    cout << '+';
    for (int i = 0; i < n; i++) {
        cout << '-';
    }
    cout << '+' << endl;

    // Бокові сторони квадрата
    for (int i = 0; i < n; i++) {
        cout << '|';
        for (int j = 0; j < n; j++) {
            cout << ' ';
        }
        cout << '|' << endl;
    }

    // Нижній край квадрата
    cout << '+';
    for (int i = 0; i < n; i++) {
        cout << '-';
    }
    cout << '+' << endl;

    return 0;
}