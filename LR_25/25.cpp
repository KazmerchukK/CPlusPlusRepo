#include <iostream>
using namespace std;

// Базовий клас
class Tree {
public:
    virtual void draw() const {
        cout << "Base Tree: nothing to draw" << endl;
    }
    virtual ~Tree() {} // Віртуальний деструктор
};

// Похідний клас – Дерево 1
class TreeType1 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 1:\n";
        cout << "  /\\\n";
        cout << " //\\\\\n";
    }
};

// Похідний клас – Дерево 2
class TreeType2 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 2:\n";
        cout << "  /\\\n";
        cout << " /**\\\n";
    }
};

// Похідний клас – Дерево 3
class TreeType3 : public Tree {
public:
    void draw() const override {
        cout << "Drawing 3:\n";
        cout << "  /\\\n";
        cout << " /++\\\n";
    }
};

int main() {
    // Масив покажчиків на базовий клас
    Tree* forest[3];

    // Різні дерева
    forest[0] = new TreeType1();
    forest[1] = new TreeType2();
    forest[2] = new TreeType3();

    // Виклик draw() поліморфно
    for (int i = 0; i < 3; ++i) {
        forest[i]->draw();
        cout << endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < 3; ++i) {
        delete forest[i];
    }

    return 0;
}
