#include <iostream>
using namespace std;

int main() {
    int n;
    long long product = 1;

    for (int i = 0; i < 10; ++i) {
        cout << "Enter a natural number: ";
        cin >> n;

        if (n <= 0) {
            cout << "The number must be a natural number! Try again." << endl;
            --i;
        }
        else {
            product *= n;
        }
    }

    cout << "Product of numbers: " << product << endl;

    return 0;
}
