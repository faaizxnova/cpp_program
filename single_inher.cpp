#include <iostream>
#include <string>

using namespace std;

class Person {
    public:
        string name;
        int age;

    Person() {
        this -> name = name;
        this -> age = age;
    }

    void getData() {
        cout << "Enter a name :";
        cin >> name;
        cout << "Enter a age :";
        cin >> age;
    }
};

class Student : public Person {
    public:
        int roll_no;

    Student() {
        this -> roll_no = roll_no;
    }

    void getRoll() {
        getData();
        cout << "Enter Roll no :";
        cin >> roll_no;
    }
};

int main(void) {
    Student faaiz;
    faaiz.getRoll();
    cout << "-----------------------------" << endl;
    cout << "Name :" << faaiz.name << endl;
    cout << "Age :" << faaiz.age << endl;
    cout << "Roll no :" << faaiz.roll_no << endl;
    cout << "-----------------------------";
    return 0;
}