#include <iostream>
#include <iomanip> 
using namespace std;

struct Date {
    int hours;
    int minutes;
};

// ������� ��� ��������� �� �� ����
Date addMinutes(Date time, int minutesToAdd) {
    time.minutes += minutesToAdd;         // ������ ��
    time.hours += time.minutes / 60;      // ������ ������, �������� � ��
    time.minutes %= 60;                   //�������� �� �� ����������
    time.hours %= 24;                     // �������� 24 �������� 
    return time;
}

// �������� �����
bool isValidTime(int hours, int minutes) {
    return (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60);
}

int main() {
    Date time;
    int additionalMinutes;

    cout << "����� ������ (0-23): ";
    cin >> time.hours;
    cout << "����� ������� (0-59): ";
    cin >> time.minutes;
    cout << "������ ������� ������ ��� ���������: ";
    cin >> additionalMinutes;

    // �������� �����
    if (!isValidTime(time.hours, time.minutes)) {
        cout << "����������� ���. ������ ����� ���� �� 0 �� 23, � ������� �� 0 �� 59." << endl;
        return 1;
    }

    // ��������� ������ � ���������� ������ ����
    Date newTime = addMinutes(time, additionalMinutes);

    cout << "����� ���: " << setw(2) << setfill('0') << newTime.hours << ":"
        << setw(2) << setfill('0') << newTime.minutes << endl;

    return 0;
}
