#include <iostream>
#include <iomanip>
using namespace std;

struct Date {
    int hours;
    int minutes;
};

//перевірка вводу
bool isValidTime(int hours, int minutes) {
    return (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60);
}

// розрахунок різниці в часі
Date calculateDuration(Date start, Date end) {
    int startTotalMinutes = start.hours * 60 + start.minutes;
    int endTotalMinutes = end.hours * 60 + end.minutes;

    //якщо подія перетинає опівночі
    if (endTotalMinutes < startTotalMinutes) {
        endTotalMinutes += 24 * 60; // додаємо 24год
    }

    int durationMinutes = endTotalMinutes - startTotalMinutes;

    Date duration;
    duration.hours = durationMinutes / 60; // год
    duration.minutes = durationMinutes % 60; // хв
    return duration;
}

int main() {
    Date startTime, endTime;

    //  ввід часу початку
    cout << "Введіть час початку події (год та хв): ";
    cin >> startTime.hours >> startTime.minutes;

    // перевірка коректності
    if (!isValidTime(startTime.hours, startTime.minutes)) {
        cout << "Некоректний час початку.Години мають бути від 0 до 23, а хвилини від 0 до 59." << endl;
        return 1;
    }

    // вві часу закінчення
    cout << "Введіть час закінчення події (год та хв):";
    cin >> endTime.hours >> endTime.minutes;

    // перевірка
    if (!isValidTime(endTime.hours, endTime.minutes)) {
        cout << "Некоректний час закінчення. Години мають бути від 0 до 23, а хвилини від 0 до 59." << endl;
        return 1;
    }

    // тривалість
    Date duration = calculateDuration(startTime, endTime);

    cout << "Тривалість події: " << duration.hours << ":"
        << setw(2) << setfill('0') << duration.minutes << endl;

    return 0;
}
