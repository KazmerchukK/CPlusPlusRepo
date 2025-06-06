
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    const int m = 5;
    const int n = 7;


    int array[m][n];


    srand(static_cast<unsigned int>(time(0)));


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            array[i][j] = rand() % 100 + 1;
        }
    }


    cout << "The arrays: " << "\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }

    cout << "\nSum of even numbers in each row:" << "\n";

    for (int i = 0; i < m; i++) {
        int row_sum = 0;
        for (int j = 0; j < n; j++) {
            row_sum += array[i][j];
        }
        cout << "row " << i + 1 << ": " << row_sum << "\n";
    }

    return 0;
}