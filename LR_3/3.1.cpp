#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Enter a three-digit number:";
    cin >> N;

    if (N >= 100 && N <= 999) {

        int hundreds = N / 100;
        int tens = (N / 10) % 10;
        int units = N % 10;

        int odd_count = 0;

        if (hundreds % 2 != 0) {
            odd_count++;
        }

        if (tens % 2 != 0) {
            odd_count++;
        }

        if (units % 2 != 0) {
            odd_count++;
        }

        cout << "Number of odd numbers:" << odd_count << endl;
    }
    else {
        cout << "Error: the number is not a three-digit number!" << endl;
    }

    return 0;
}