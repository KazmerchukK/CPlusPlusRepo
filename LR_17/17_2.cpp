#include <iostream>
using namespace std;

// Функція перевіряє, чи є число простим
bool isPrime(int num) {
    if (num <= 1) return false; // 0 та 1 не є простими
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false; // Якщо знайшли дільник, число не є простим
    }
    return true; // Якщо дільників немає, число просте
}

int main(void) {
    for (int i = 0; i <= 21; i++) {
        if (isPrime(i))
            cout << i << " ";
    }
    cout << endl;
    return 0;
}
