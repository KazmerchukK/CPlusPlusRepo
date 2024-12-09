
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    const int m = 3;
    const int n = 3;


    int array[m][n];


    srand(static_cast<unsigned int>(time(0)));


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 50 + 1;
        }
    }


    cout << "The arrays: " << "\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    int main_diagonal_sum = 0;
    int secondary_diagonal_sum = 0;

    for (int i = 0; i < m; i++) {
        main_diagonal_sum += array[i][i];
        secondary_diagonal_sum += array[i][n - i - 1];

    }
    cout << "\nthe sum of numbers along the main diagonal: " << main_diagonal_sum << "\n";
    cout << "The sum of the numbers on the side diagonal: " << secondary_diagonal_sum << "\n";
    return 0;
}

