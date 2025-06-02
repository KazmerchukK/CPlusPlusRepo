#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int n = 20; 
    float* arr = new float[n]; // динамічне виділення пам'яті

    // випадкові чилсли
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // заповняємо ними масив
    for (int i = 0; i < n; ++i) {
        float num = static_cast<float>(std::rand()) / RAND_MAX; // [0, 1)
        arr[i] = num * 4.0f - 2.0f; // збільшення до [-2, 2)
    }

    // рахуємо + і -
    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            positiveCount++;
        } else if (arr[i] < 0) {
            negativeCount++;
        }
    }

    std::cout << "Масив:\n";
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\nКількість додатних чисел: " << positiveCount << std::endl;
    std::cout << "Кількість від'ємних чисел: " << negativeCount << std::endl;

    // Звільнення динамічної пам'яті
    delete[] arr;

    return 0;
}
