#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a, b, x;

    cout << "Enter the value a: ";
    cin >> a;

    cout << "Enter the value b:  ";
    cin >> b;

    double root_a = cbrt(a);
    double root_b = cbrt(b);

    x = (0.81 * root_a - (1 / 2.125) * root_b) * exp(a);

    cout << "Result: " << x << endl;

    return 0;
}