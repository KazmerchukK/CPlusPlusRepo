#include <iostream>
#include <string>
using namespace std;

class Person {
public:
    string name;
    int age;
    string gender;
    string city;
    double height; // у см
};

void print(Person* person) {
    cout << person->name << " is " << person->age << " years old" << endl;
    cout << "Gender: " << person->gender << endl;
    cout << "City: " << person->city << endl;
    cout << "Height: " << person->height << " cm" << endl;
}

int main() {
    Person person;
    person.name = "Harry";
    person.age = 23;
    person.gender = "Male";
    person.city = "London";
    person.height = 178.5;

    cout << "Meet " << person.name << "!" << endl;
    print(&person);

    return 0;
}
