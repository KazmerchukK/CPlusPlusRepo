#include <iostream>
#include <iomanip> // для встановлення точності виводу
using namespace std;

int main(void) {
    double pi4 = 0.0; // змінна для обчислення π/4
    long n; // кількість ітерацій

    cout << "Number of iterations? ";
    cin >> n;

    // Перевірка на коректність введеного числа
    if (n <= 0) {
        cout << "The number of iterations must be positive." << endl;
        return 1;
    }

    // Обчислення π/4 за формулою Лейбніца
    for (long i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            pi4 += 1.0 / (2.0 * i + 1.0); // додавання для парних i
        }
        else {
            pi4 -= 1.0 / (2.0 * i + 1.0); // віднімання для непарних i
        }
    }

    // Виведення результату з високою точністю
    cout << fixed << setprecision(20);
    cout << "Pi = " << (pi4 * 4.0) << endl;

    return 0;
}
