#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    FlightBooking();
    void printStatus() const;
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);
    int getId() const { return id; }

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
    : id(id), capacity(capacity), reserved(reserved) {}

FlightBooking::FlightBooking() {
    id = 0;
    capacity = 0;
    reserved = 0;
}

void FlightBooking::printStatus() const {
    int percentage = (capacity == 0) ? 0 : (reserved * 100 / capacity);
    cout << "Flight " << id << " : " << reserved << "/" << capacity
         << " (" << percentage << "%) seats reserved" << endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    if (reserved + number_of_seats > capacity) {
        return false;
    }
    reserved += number_of_seats;
    return true;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (reserved - number_of_seats < 0) {
        return false;
    }
    reserved -= number_of_seats;
    return true;
}

// Search flight by ID
int findFlight(FlightBooking flights[], int id) {
    for (int i = 0; i < 10; ++i) {
        if (flights[i].getId() == id)
            return i;
    }
    return -1;
}

void listFlights(FlightBooking flights[]) {
    bool any = false;
    for (int i = 0; i < 10; ++i) {
        if (flights[i].getId() != 0) {
            flights[i].printStatus();
            any = true;
        }
    }
    if (!any)
        cout << "No flights in the system" << endl;
}

int main() {
    FlightBooking flights[10]; // max 10 flights
    string command;

    while (true) {
        cout << "What would you like to do?: ";
        getline(cin, command);
        if (command == "quit")
            break;

        stringstream ss(command);
        string cmd;
        ss >> cmd;

        if (cmd == "create") {
            int id, cap;
            ss >> id >> cap;
            if (findFlight(flights, id) != -1) {
                cout << "Cannot perform this operation: flight " << id << " already exists" << endl;
                continue;
            }
            int idx = findFlight(flights, 0);
            if (idx == -1) {
                cout << "Cannot perform this operation: flight limit reached" << endl;
                continue;
            }
            flights[idx] = FlightBooking(id, cap, 0);
        }
        else if (cmd == "delete") {
            int id;
            ss >> id;
            int idx = findFlight(flights, id);
            if (idx == -1) {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
                continue;
            }
            flights[idx] = FlightBooking(); // reset flight to empty
        }
        else if (cmd == "add") {
            int id, n;
            ss >> id >> n;
            int idx = findFlight(flights, id);
            if (idx == -1) {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
                continue;
            }
            if (!flights[idx].reserveSeats(n)) {
                cout << "Cannot perform this operation: capacity reached" << endl;
            }
        }
        else if (cmd == "cancel") {
            int id, n;
            ss >> id >> n;
            int idx = findFlight(flights, id);
            if (idx == -1) {
                cout << "Cannot perform this operation: flight " << id << " not found" << endl;
                continue;
            }
            if (!flights[idx].cancelReservations(n)) {
                cout << "Cannot perform this operation: not enough reserved seats" << endl;
            }
        }
        else {
            cout << "Invalid command" << endl;
        }

        listFlights(flights);
    }

    return 0;
}
