#include <iostream>
using namespace std;

int main(void) {
    int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
    int n = sizeof(vector) / sizeof(vector[0]); // 9

    int *p = vector;      
    int *min = vector;   

    for (int i = 1; i < n; i++) {
        if (*(p + i) < *min) {
            min = p + i; 
        }
    }

    cout << "min: " << *min << endl;

    return 0;
}
