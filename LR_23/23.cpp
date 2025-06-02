#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

class Fraction {
public:
    Fraction(int numerator = 0, int denominator = 1);
    string toString() const;
    double toDouble() const;

    Fraction plus(Fraction that) const;
    Fraction minus(Fraction that) const;
    Fraction times(Fraction that) const;
    Fraction by(Fraction that) const;

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
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
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

Fraction Fraction::plus(Fraction that) const {
    int num = this->numerator * that.denominator + that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::minus(Fraction that) const {
    int num = this->numerator * that.denominator - that.numerator * this->denominator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::times(Fraction that) const {
    int num = this->numerator * that.numerator;
    int den = this->denominator * that.denominator;
    return Fraction(num, den);
}

Fraction Fraction::by(Fraction that) const {
    int num = this->numerator * that.denominator;
    int den = this->denominator * that.numerator;
    if (den < 0) {
        num = -num;
        den = -den;
    }
    return Fraction(num, den);
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

    cout << f1.toString() << " + " << f2.toString() << " = " << f1.plus(f2).toString() << endl;
    cout << f1.toString() << " - " << f2.toString() << " = " << f1.minus(f2).toString() << endl;
    cout << f1.toString() << " * " << f2.toString() << " = " << f1.times(f2).toString() << endl;
    cout << f1.toString() << " / " << f2.toString() << " = " << f1.by(f2).toString() << endl;

    return 0;
}
