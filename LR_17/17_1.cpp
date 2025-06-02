#include <iostream>

//функц перевірити чи просте число
bool isPrime(int n) {
    if (n <= 1) return false; // числа менші або рівні 1 не є простими
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false; // якщо знайдено дільник, число не є простим
    }
    return true; // якщо не знайдено, число просте
}

int main() {
    int number;
    std::cout << "Введіть число: ";
    std::cin >> number;

    if (isPrime(number)) {
        std::cout << number << " є простим числом.\n";
    } else {
        std::cout << number << " не є простим числом.\n";
    }

    return 0;
}
