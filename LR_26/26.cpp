#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

// Базовий клас IPAddress
class IPAddress {
protected:
    string ip;

public:
    IPAddress(string ip) : ip(ip) {}

    IPAddress(const IPAddress& other) {
        ip = other.ip;
    }

    virtual void print() const {
        cout << ip;
    }

    virtual ~IPAddress() {}
};

// Перевірка IP (приватна допоміжна функція)
bool isValidIP(const string& ip) {
    stringstream ss(ip);
    string segment;
    int parts = 0;

    while (getline(ss, segment, '.')) {
        if (segment.empty() || segment.size() > 3) return false;

        for (char c : segment) {
            if (!isdigit(c)) return false;
        }

        int num = stoi(segment);
        if (num < 0 || num > 255) return false;

        ++parts;
    }

    return parts == 4;
}

// Похідний клас
class IPAddressChecked : public IPAddress {
    bool isCorrect;

public:
    IPAddressChecked(string ip) : IPAddress(ip) {
        isCorrect = isValidIP(ip);
    }

    IPAddressChecked(const IPAddressChecked& other) : IPAddress(other) {
        isCorrect = other.isCorrect;
    }

    void print() const override {
        IPAddress::print();
        cout << " - " << (isCorrect ? "Correct" : "Not Correct");
    }
};

int main() {
    string ip1, ip2, ip3;
    getline(cin, ip1);
    getline(cin, ip2);
    getline(cin, ip3);

    IPAddress ipA(ip1);
    IPAddressChecked ipB(ip2);
    IPAddressChecked ipC(ip3);

    ipA.print();
    cout << endl;
    ipB.print();
    cout << endl;
    ipC.print();
    cout << endl;

    return 0;
}
