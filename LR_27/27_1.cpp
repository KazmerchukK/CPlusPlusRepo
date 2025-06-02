#include <iostream>
using namespace std;

int main(void) {
    int a = 8, b = 0, c = 0;
    cin >> b;

    try {
        if (b == 0) {
            throw "Your input is not valid, you can't divide by zero.";
        }
        c = a / b;
        cout << c << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
        cout << 0 << endl;
    }

    return 0;
}
