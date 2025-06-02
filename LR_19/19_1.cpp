#include <iostream>
#include <string>
#include <map>
#include <sstream>

// Функція для розділення строки на ключ-значення і збереження їх у map
std::map<std::string, std::string> parseValues(const std::string& values) {
    std::map<std::string, std::string> result;
    std::stringstream ss(values);
    std::string pair;

    while (std::getline(ss, pair, ',')) {
        size_t eqPos = pair.find('=');
        if (eqPos != std::string::npos) {
            std::string key = pair.substr(0, eqPos);
            std::string value = pair.substr(eqPos + 1);
            result[key] = value;
        }
    }
    return result;
}

// Функція для заповнення шаблону відповідними значеннями
std::string fillTemplate(const std::string& temp, const std::map<std::string, std::string>& values) {
    std::string result;
    size_t i = 0;

    while (i < temp.size()) {
        if (temp[i] == '[') {
            size_t end = temp.find(']', i);
            if (end != std::string::npos) {
                std::string key = temp.substr(i + 1, end - i - 1);
                if (values.count(key)) {
                    result += values.at(key);
                } else {
                    result += "[" + key + "]";
                }
                i = end + 1;
            } else {
                result += temp[i];
                ++i;
            }
        } else {
            result += temp[i];
            ++i;
        }
    }

    return result;
}

int main() {
    std::string values;
    std::getline(std::cin, values);
    std::string temp;
    std::getline(std::cin, temp);

    std::map<std::string, std::string> replacements = parseValues(values);
    std::string output = fillTemplate(temp, replacements);

    std::cout << output << std::endl;

    return 0;
}
