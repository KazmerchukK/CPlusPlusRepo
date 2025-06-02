#include <iostream>
using namespace std;

// --- Approach 1: Always compute when needed ---
class AdHocSquare {
public:
    AdHocSquare(double side);
    void set_side(double side);
    double get_area();
private:
    double side;
};

AdHocSquare::AdHocSquare(double s) {
    side = s;
}

void AdHocSquare::set_side(double s) {
    side = s;
}

double AdHocSquare::get_area() {
    return side * side;
}

// --- Approach 2: Lazy computation (only when needed) ---
class LazySquare {
public:
    LazySquare(double side);
    void set_side(double side);
    double get_area();
private:
    double side;
    double area;
    bool side_changed;
};

LazySquare::LazySquare(double s) {
    side = s;
    area = side * side;
    side_changed = false;
}

void LazySquare::set_side(double s) {
    if (side != s) {
        side = s;
        side_changed = true;
    }
}

double LazySquare::get_area() {
    if (side_changed) {
        area = side * side;
        side_changed = false;
    }
    return area;
}

int main() {
    cout << "AdHocSquare test:\n";
    AdHocSquare a(4);
    cout << a.get_area() << endl; // 16
    a.set_side(5);
    cout << a.get_area() << endl; // 25

    cout << "\nLazySquare test:\n";
    LazySquare l(4);
    cout << l.get_area() << endl; // 16
    l.set_side(5);
    cout << l.get_area() << endl; // 25
    cout << l.get_area() << endl; // 25 (no recalculation)
    
    return 0;
}

