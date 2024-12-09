#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;

    cout << "Enter four numbers (each between 1 and 255): " << endl;
    cin >> a >> b >> c >> d;

    if ((a >= 1 && a <= 255) && (b >= 1 && b <= 255) &&
        (c >= 1 && c <= 255) && (d >= 1 && d <= 255)) {
        cout << "IP Address: " << a << "." << b << "." << c << "." << d << endl;
    }
    else {
        cout << "Invalid input! Numbers must be between 1 and 255." << endl;
    }

    return 0;
}