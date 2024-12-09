
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    const int m = 3;
    const int n = 4;


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


    int max_value = array[0][0];
    int max_row = 0, max_col = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] > max_value) {
                max_value = array[i][j];
                max_row = i;
                max_col = j;
            }
        }
    }

    cout << "\nThe maximum element in the array: " << max_value << "\n";
    cout << "Its position: row " << max_row + 1 << ", column " << max_col + 1 << "\n";

    return 0;
}