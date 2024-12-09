#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double A, C, x, y;

    cout << "Enter the value A: ";
    cin >> A;
    cout << "Enter the value C: ";
    cin >> C;
    cout << "Enter the value x: ";
    cin >> x;


    if (A == C) {
        y = x * pow(A - C, 3);
    }
    else if (A > C) {
        y = pow(x, 3) - A;
    }
    else {
        y = x + pow(A, 3);
    }

    cout << "Result Y: " << y << endl;

    return 0;
}