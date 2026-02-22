#include <iostream>
#include <string>

using namespace std;

class Animal {
    public:
    void Eating() {
        cout << "Animal is eating " << endl;
    }
};

class Cat : public Animal {
    public:
    void call() {
        Eating();
        cout << "Animal call meow meow!";
    }
};

int main() {
    Cat kitty;
    kitty.call();
    return 0;
}