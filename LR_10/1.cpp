#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    const int m = 4;
    const int n = 3;


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

    cout << "\nNumber of even numbers in each row:" << "\n";

    // Calculating the number of even numbers in each string
    for (int i = 0; i < m; i++) {
        int even_count = 0;
        for (int j = 0; j < n; j++) {
            if (array[i][j] % 2 == 0) {
                even_count++;
            }
        }
        cout << "Row " << i + 1 << ": " << even_count << "\n";
    }

    return 0;
}