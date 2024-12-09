#include <iostream>
using namespace std;

int main() {
    int month;
    cout << "Enter the month number (from 1 to 7): ";
    cin >> month;

    switch (month) {
        case 1:
            cout << "Січень - January" << endl;
            break;
        case 2:
            cout << "Лютий - February" << endl;
            break;
        case 3:
            cout << "Березень - March" << endl;
            break;
        case 4:
            cout << "Квітень - April" << endl;
            break;
        case 5:
            cout << "Травень - May" << endl;
            break;
        case 6:
            cout << "Червень - June" << endl;
            break;
        case 7:
            cout << "Липень - July" << endl;
            break;
        default:
            cout << "Wrong month number! Enter a number from 1 to 7." << endl;
    }

    return 0;
}