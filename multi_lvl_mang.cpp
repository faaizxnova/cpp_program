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

    void getGeneral() {
        cout << "Enter your name :";
        cin >> name;

        cout << "Enter your age :";
        cin >> age;
    }
};

class Employee : public Person {
    public:
        int salary;

    Employee() {
        this -> salary = salary;
    }

    void getSalary() {
        cout << "Enter your salary :";
        cin >> salary;
    }
};

class Manager : public Employee {
    public:
        bool client_acess = true;
        
    Manager() {
        this -> client_acess = client_acess;
    }

    void is_client() {
        getGeneral();
        getSalary();
        if(client_acess) 
            cout << "Client Acess Gratent!";
    }
};

int main() {
    Manager faaiz;
    faaiz.is_client();
}