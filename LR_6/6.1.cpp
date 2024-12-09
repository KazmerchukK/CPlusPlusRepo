#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Введіть натуральне число N: ";
    cin >> N;

    // Зберігаємо копію числа для обчислень
    int originalN = N;

    // Визначаємо останню цифру
    int lastDigit = N % 10;

    // Обчислюємо кількість цифр та першу цифру
    int firstDigit = N;
    int factor = 1;
    while (firstDigit >= 10) {
        firstDigit /= 10;
        factor *= 10;
    }

    // Якщо число складається з однієї цифри, то перестановка не потрібна
    if (factor == 1) {
        cout << "Число складається з однієї цифри: " << originalN << endl;
        return 0;
    }

    // Видаляємо першу та останню цифру
    int middlePart = (N % factor) / 10;

    // Формуємо нове число з переставленими першою та останньою цифрою
    int newNumber = lastDigit * factor + middlePart * 10 + firstDigit;

    cout << "Число з переставленими першою та останньою цифрами: " << newNumber << endl;

    return 0;
}
