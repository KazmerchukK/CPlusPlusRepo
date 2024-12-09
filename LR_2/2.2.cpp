#include <iostream>

using namespace std;

int main() {
    double x, y;

    cout << "Enter the coordinates of the point (x, y): " << endl;
    cin >> x >> y;

    if ((x >= -1 && x <= 0) && (y >= 0 && y <= 1)) {
        cout << "The point is in the shaded area (left part)." << endl;
    }
    else if ((x >= 0 && x <= 1) && (y >= -1 && y <= 0)) {
        cout << "The point is in the shaded area (right part)." << endl;
    }
    else {
        cout << "The point is not in the shaded area." << endl;
    }

    return 0;
}