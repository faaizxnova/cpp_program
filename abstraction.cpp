#include <iostream>
#include <string>

using namespace std;

class Vechicle {
    public:
        virtual void name() = 0;
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

    v = new Rolls();
    v -> name();
} 