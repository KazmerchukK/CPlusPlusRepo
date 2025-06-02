#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    int rows = 3, cols = 3;

    // виділення динамічної пам’яті для масиву
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // заповнення масиву
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            matrix[i][j] = std::rand() % 21 - 10; // [-10, 10]
        }
    }

    std::cout << "Матриця 3x3:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << "\n";
    }

    // Виведення елементів головної діагоналі
    std::cout << "\nГоловна діагональ: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << matrix[i][i] << " ";
    }

    // Виведення елементів побічної діагоналі
    std::cout << "\nПобічна діагональ: ";
    for (int i = 0; i < 3; ++i) {
        std::cout << matrix[i][2 - i] << " ";
    }

    // рахуємо скільки парних та непарних елементів
    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] % 2 == 0) {
                evenCount++;
            } else {
                oddCount++;
            }
        }
    }

    std::cout << "\nКількість парних елементів: " << evenCount;
    std::cout << "\nКількість непарних елементів: " << oddCount << std::endl;

    // Звільнення динамічної пам’яті
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
