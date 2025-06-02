#include <iostream>
using namespace std;

// Перевантажена функція з одним аргументом
void increment(int &a) {
    a += 1;
}

// Перевантажена функція з двома аргументами
void increment(int &a, int b) {
    a += b;
}

int main(void) {
    int var = 0;
    for(int i = 0; i < 10; i++)
        if(i % 2)
            increment(var);
        else
            increment(var, i);
    cout << var << endl;
    return 0;
}
