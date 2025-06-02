#include <iostream>
#include <sstream>
#include <string>
#include <cmath>
using namespace std;

class Fraction {
public:
    Fraction(int numerator, int denominator);
    string toString();
    double toDouble();

private:
    int numerator;
    int denominator;
};

Fraction::Fraction(int numerator, int denominator) {
    // Ensure denominator is always positive
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;
}

string Fraction::toString() {
    int num = numerator;
    int den = denominator;

    if (abs(num) >= den) {
        int whole = num / den;
        int rem = abs(num % den);
        if (rem == 0)
            return to_string(whole);
        else
            return to_string(whole) + " " + to_string(rem) + "/" + to_string(den);
    } else {
        return to_string(num) + "/" + to_string(den);
    }
}

double Fraction::toDouble() {
    return static_cast<double>(numerator) / denominator;
}

int main() {
    string input;
    cout << "Enter a fraction (e.g., 3 / 4): ";
    getline(cin, input);

    int num, den;
    char slash;
    stringstream ss(input);
    ss >> num >> slash >> den;

    if (den == 0) {
        cout << "Denominator cannot be zero." << endl;
        return 1;
    }

    Fraction fraction(num, den);
    cout << fraction.toString() << " is " << fraction.toDouble() << " in decimal" << endl;

    return 0;
}
