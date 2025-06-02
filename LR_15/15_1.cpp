#include <iostream>
using namespace std;

// перевірка, чи рік є високосним
bool isLeap(int year) {
    // високосний якщо кратний 4, але не кратний 100
    // або кратний 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(void) {
    for(int yr = 1995; yr < 2017; yr++) {
        cout << yr << " -> " << isLeap(yr) << endl;
    }
    return 0;
}
