#include <iostream>
#include <iomanip> 
using namespace std;

struct Date {
    int hours;
    int minutes;
};

// функція для додавання хв до часу
Date addMinutes(Date time, int minutesToAdd) {
    time.minutes += minutesToAdd;         // додаємо хв
    time.hours += time.minutes / 60;      // додаємо години, отриманні з хв
    time.minutes %= 60;                   //залишаємо хв які залишились
    time.hours %= 24;                     // обмежуємо 24 годинами 
    return time;
}

// перевірка вводу
bool isValidTime(int hours, int minutes) {
    return (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60);
}

int main() {
    Date time;
    int additionalMinutes;

    cout << "Введіт години (0-23): ";
    cin >> time.hours;
    cout << "Введіт хвилини (0-59): ";
    cin >> time.minutes;
    cout << "Введіть кількість хвилин для додавання: ";
    cin >> additionalMinutes;

    // перевірка вводу
    if (!isValidTime(time.hours, time.minutes)) {
        cout << "Некоректний час. Години мають бути від 0 до 23, а хвилини від 0 до 59." << endl;
        return 1;
    }

    // Додавання хвилин і розрахунок нового часу
    Date newTime = addMinutes(time, additionalMinutes);

    cout << "Новий час: " << setw(2) << setfill('0') << newTime.hours << ":"
        << setw(2) << setfill('0') << newTime.minutes << endl;

    return 0;
}
