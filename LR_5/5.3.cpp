#include <iostream>
#include <cmath> 
#include <iomanip> 
using namespace std;

int main() {
    double a, b, h, x, y;

    cout << "Enter the initial segment (a): ";
    cin >> a;
    cout << "Enter the end of segment (b): ";
    cin >> b;
    cout << "Enter step (h): ";
    cin >> h;

    if (h <= 0) {
        cout << "Step h must be greater than 0!" << endl;
        return 1;
    }

    x = a;

    cout << "-------------------" << endl;
    cout << ":    X    :    Y   :" << endl;
    cout << "-------------------" << endl;

    while (x <= b) {
        if (cos(x) < 0) {
            cout << "The value of x =" << x << " does not belong to ODZ (cos(x) < 0)." << endl;
            break;
        }

        y = sqrt(cos(x)) + sin(x);

        cout << fixed << setprecision(4);
        cout << ": " << setw(6) << x << " : " << setw(6) << y << " :" << endl;

        x += h;
    }

    cout << "-------------------" << endl;

    return 0;
}
