#include <iostream>
#include <string>
#include <sstream>

class FlightBooking {
public:
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    bool reserveSeats(int number_of_seats);
    bool cancelReservations(int number_of_seats);

private:
    int id;
    int capacity;
    int reserved;
};

FlightBooking::FlightBooking(int id, int capacity, int reserved)
    : id(id), capacity(capacity) {
    int maxSeats = static_cast<int>(capacity * 1.05);
    if (reserved < 0)
        this->reserved = 0;
    else if (reserved > maxSeats)
        this->reserved = maxSeats;
    else
        this->reserved = reserved;
}

void FlightBooking::printStatus() {
    double percentage = (static_cast<double>(reserved) / capacity) * 100;
    std::cout << "Flight " << id << " : " << reserved << "/" << capacity
              << " (" << static_cast<int>(percentage) << "%) seats reserved" << std::endl;
}

bool FlightBooking::reserveSeats(int number_of_seats) {
    int maxSeats = static_cast<int>(capacity * 1.05);
    if (number_of_seats < 0 || reserved + number_of_seats > maxSeats)
        return false;
    reserved += number_of_seats;
    return true;
}

bool FlightBooking::cancelReservations(int number_of_seats) {
    if (number_of_seats < 0 || reserved - number_of_seats < 0)
        return false;
    reserved -= number_of_seats;
    return true;
}

int main() {
    int reserved = 0, capacity = 0;
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;
    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;
    std::cin.ignore();  // Clear newline from input buffer

    FlightBooking booking(1, capacity, reserved);
    std::string command = "";

    while (command != "quit") {
        booking.printStatus();
        std::cout << "What would you like to do?: ";
        std::getline(std::cin, command);

        std::istringstream iss(command);
        std::string action;
        int number;

        iss >> action >> number;

        if (action == "add") {
            if (!booking.reserveSeats(number))
                std::cout << "Cannot perform this operation" << std::endl;
        } else if (action == "cancel") {
            if (!booking.cancelReservations(number))
                std::cout << "Cannot perform this operation" << std::endl;
        } else if (action != "quit" && !action.empty()) {
            std::cout << "Unknown command" << std::endl;
        }
    }

    return 0;
}
