#include <iostream>
using namespace std;

class Square {
private:
    double side;
    double area;

public:
    Square(double side);
    void set_side(double side);
    void print();
};

Square::Square(double side) {
    set_side(side); // використовуємо set_side, щоб автоматично встановити area і перевірити значення
}

void Square::set_side(double s) {
    if (s < 0)
        return; // ігноруємо негативні значення
    side = s;
    area = side * side;
}

void Square::print() {
    cout << "Square: side=" << side << " area=" << area << endl;
}

int main() {
    Square square(4);
    square.print();

    square.set_side(2.0); // правильне оновлення
    square.print();

    square.set_side(-33.0); // ігнорується
    square.print();

    return 0;
}
