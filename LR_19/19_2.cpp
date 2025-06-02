#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string password;
    std::getline(std::cin, password);

    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;

    for (char ch : password) {
        if (std::isupper(ch)) has_upper = true;
        else if (std::islower(ch)) has_lower = true;
        else if (std::isdigit(ch)) has_digit = true;
        else has_special = true;
    }

    bool valid = true;

    if (password.length() < 8) {
        std::cout << "The password must be 8 characters long\n";
        valid = false;
    }
    if (!has_upper) {
        std::cout << "The password must have at least one upper case letter\n";
        valid = false;
    }
    if (!has_lower) {
        std::cout << "The password must have at least one lower case letter\n";
        valid = false;
    }
    if (!has_digit) {
        std::cout << "The password must have at least one digit\n";
        valid = false;
    }
    if (!has_special) {
        std::cout << "The password must have at least one special character\n";
        valid = false;
    }

    if (valid) {
        std::cout << "The password is valid\n";
    }

    return 0;
}
