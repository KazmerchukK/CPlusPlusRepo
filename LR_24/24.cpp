#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1);
    string toString() const;
    double toDouble() const;

    bool isGreaterThan(Fraction that) const;
    bool isLessThan(Fraction that) const;
    bool isEqual(Fraction that) const;

private:
    int numerator;
    int denominator;
    void reduce();
};

Fraction::Fraction(int numerator, int denominator) {
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    this->numerator = numerator;
    this->denominator = denominator;
    reduce();
}

void Fraction::reduce() {
    int div = gcd(numerator, denominator);
    numerator /= div;
    denominator /= div;
}

string Fraction::toString() const {
    int whole = numerator / denominator;
    int rem = abs(numerator % denominator);

    if (rem == 0)
        return to_string(whole);

    string sign = (numerator < 0 && whole == 0) ? "-" : "";

    if (abs(numerator) < denominator)
        return sign + to_string(abs(numerator)) + "/" + to_string(denominator);

    return to_string(whole) + " " + to_string(rem) + "/" + to_string(denominator);
}

double Fraction::toDouble() const {
    return static_cast<double>(numerator) / denominator;
}

bool Fraction::isGreaterThan(Fraction that) const {
    return this->numerator * that.denominator > that.numerator * this->denominator;
}

bool Fraction::isLessThan(Fraction that) const {
    return this->numerator * that.denominator < that.numerator * this->denominator;
}

bool Fraction::isEqual(Fraction that) const {
    return this->numerator * that.denominator == that.numerator * this->denominator;
}

int main() {
    string input1, input2;
    int num1, den1, num2, den2;
    char slash;

    cout << "Enter first fraction (e.g. 3 / 4): ";
    getline(cin, input1);
    stringstream ss1(input1);
    ss1 >> num1 >> slash >> den1;

    cout << "Enter second fraction (e.g. 1 / 3): ";
    getline(cin, input2);
    stringstream ss2(input2);
    ss2 >> num2 >> slash >> den2;

    Fraction f1(num1, den1);
    Fraction f2(num2, den2);

    if (f1.isGreaterThan(f2)) {
        cout << f1.toString() << " > " << f2.toString() << endl;
    } else if (f1.isLessThan(f2)) {
        cout << f1.toString() << " < " << f2.toString() << endl;
    } else {
        cout << f1.toString() << " = " << f2.toString() << endl;
    }

    return 0;
}
