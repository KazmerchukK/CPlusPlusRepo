#include <iostream>
#include <iomanip>
using namespace std;

struct Date {
    int hours;
    int minutes;
};

//�������� �����
bool isValidTime(int hours, int minutes) {
    return (hours >= 0 && hours < 24 && minutes >= 0 && minutes < 60);
}

// ���������� ������ � ���
Date calculateDuration(Date start, Date end) {
    int startTotalMinutes = start.hours * 60 + start.minutes;
    int endTotalMinutes = end.hours * 60 + end.minutes;

    //���� ���� �������� �������
    if (endTotalMinutes < startTotalMinutes) {
        endTotalMinutes += 24 * 60; // ������ 24���
    }

    int durationMinutes = endTotalMinutes - startTotalMinutes;

    Date duration;
    duration.hours = durationMinutes / 60; // ���
    duration.minutes = durationMinutes % 60; // ��
    return duration;
}

int main() {
    Date startTime, endTime;

    //  ��� ���� �������
    cout << "������ ��� ������� ��䳿 (��� �� ��): ";
    cin >> startTime.hours >> startTime.minutes;

    // �������� ����������
    if (!isValidTime(startTime.hours, startTime.minutes)) {
        cout << "����������� ��� �������.������ ����� ���� �� 0 �� 23, � ������� �� 0 �� 59." << endl;
        return 1;
    }

    // �� ���� ���������
    cout << "������ ��� ��������� ��䳿 (��� �� ��):";
    cin >> endTime.hours >> endTime.minutes;

    // ��������
    if (!isValidTime(endTime.hours, endTime.minutes)) {
        cout << "����������� ��� ���������. ������ ����� ���� �� 0 �� 23, � ������� �� 0 �� 59." << endl;
        return 1;
    }

    // ���������
    Date duration = calculateDuration(startTime, endTime);

    cout << "��������� ��䳿: " << duration.hours << ":"
        << setw(2) << setfill('0') << duration.minutes << endl;

    return 0;
}
