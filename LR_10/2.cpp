#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    const int m = 6;
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

    cout << "\nNumber of even numbers in each column:" << "\n";

    for (int j = 0; j < n; j++) {
        int even_count = 0;
        for (int i = 0; i < m; i++) {
            if (array[i][j] % 2 == 0) {
                even_count++;
            }
        }
        cout << "column " << j + 1 << ": " << even_count << "\n";
    }

    return 0;
}