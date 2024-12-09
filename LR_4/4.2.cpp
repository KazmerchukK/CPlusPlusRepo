#include <iostream>
#include <iomanip> 

using namespace std;

int main() {
    float var1, var2, var3, var4, var5;

    cout << "Enter five floating-point numbers:" << endl;
    cin >> var1 >> var2 >> var3 >> var4 >> var5;

    cout << "Output:" << endl;
    cout << var1 << endl;
    cout << fixed << setprecision(2) << var2 << endl;
    cout << setprecision(6) << var3 << endl;
    cout << fixed << setprecision(2) << var4 << endl;
    cout << fixed << setprecision(0) << var5 << endl;

    return 0;
}