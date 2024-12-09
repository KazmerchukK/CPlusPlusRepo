
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    const int m = 4;
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


    int min_value = array[0][0];
    int min_row = 0, min_col = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (array[i][j] < min_value) {
                min_value = array[i][j];
                min_row = i;
                min_col = j;
            }
        }
    }

    cout << "\nThe maximum element in the array: " << min_value << "\n";
    cout << "Its position: row " << min_row + 1 << ", column " << min_col + 1 << "\n";

    return 0;
}