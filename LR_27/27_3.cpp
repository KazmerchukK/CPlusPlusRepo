#include <iostream>
using namespace std;

float div(float arg1, float arg2) {
    if (arg2 == 0.0)
        throw "Your input is not valid. You can't divide by zero.";
    return arg1 / arg2;
}

int main() {
    float a, b;
    while (cin >> a >> b) {
        try {
            float result = div(a, b);
            cout << result << endl;
        } catch (const char* msg) {
            cout << "Are you kidding me?" << endl;
            cout << msg << endl;
        }
    }
    return 0;
}
