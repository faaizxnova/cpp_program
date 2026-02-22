#include <iostream>
#include <string>

using namespace std;

class Vechicle {
    public:
        virtual void name() {
            cout << "Vechicle" << endl;
        }
};

class Rolls : public Vechicle {
    public:
        void name() {
            cout << "rolls" << endl;
        }
};

class Ferar : public Vechicle {
    public:
        void name() {
            cout << "ferar" << endl;
        }
};

int main(void) {
    Vechicle *v;

    Rolls r;
    Ferar f;

    v = &r;
    v -> name();

    v = &f;
    v -> name();
} 