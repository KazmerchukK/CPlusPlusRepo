#include <iostream>
#include <cmath>

using namespace std;

int main() {

    double a, b, x;

    cout << "Enter the value a: ";
    cin >> a;

    cout << "Enter the value b: ";
    cin >> b;

    double sinus = sin((a - b) * M_PI_4);
    double cosinus = cos((b + a) * M_PI_4);

    double numerator = 0.807 * (1 - pow(sinus, 2));
    double denominator = 0.312 * (1 + pow(cosinus, 2));
    double fraction = pow((a * a) / (b * b * b), 2.0 / 3.0);

    x = fraction * exp(numerator / denominator);


    cout << "Result: " << x << endl;

    return 0;
}