#include <iostream>
#include <ctime>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int monthLength(int year, int month) {
    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (month == 2 && isLeap(year)) {
        return 29;
    }
    return daysInMonth[month - 1];
}

Date today() {
    time_t t = time(NULL);
    tm tl = *localtime(&t);
    Date d;
    d.year = tl.tm_year + 1900;
    d.month = tl.tm_mon + 1;
    d.day = tl.tm_mday;
    return d;
}

// функц для обчислення кількості днів від початку року
int daysFromStartOfYear(Date d) {
    int days = 0;
    for (int m = 1; m < d.month; ++m) {
        days += monthLength(d.year, m);
    }
    days += d.day;
    return days;
}

// раїуємо кількості днів між двома датами
int daysBetween(Date d1, Date d2) {
    if (d1.year == d2.year) {
        return daysFromStartOfYear(d2) - daysFromStartOfYear(d1);
    }

    int days = 0;

    // дні до кінця року d1
    int daysInFirstYear = isLeap(d1.year) ? 366 : 365;
    days += daysInFirstYear - daysFromStartOfYear(d1);

    // повні роки між
    for (int y = d1.year + 1; y < d2.year; ++y) {
        days += isLeap(y) ? 366 : 365;
    }

    // дні з початку останнього року до d2
    days += daysFromStartOfYear(d2);

    return days;
}

int main() {
    Date birthDate;
    cout << "Введіть дату народження (рік місяць день): ";
    cin >> birthDate.year >> birthDate.month >> birthDate.day;

    Date now = today();
    int result = daysBetween(birthDate, now);
    cout << "Кількість днів від народження: " << result << endl;

    return 0;
}
