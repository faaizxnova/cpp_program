#include <iostream>
using namespace std;

int main() {
    int ch;
    double t;
    cout << "1.C to F\n2.F to C\n3.C to K\n4.K to C\nChoice: ";
    cin >> ch;
    cout << "Enter temperature: ";
    cin >> t;

    if (ch == 1)
        cout << (t * 9 / 5) + 32;
    else if (ch == 2)
        cout << (t - 32) * 5 / 9;
    else if (ch == 3)
        cout << t + 273.15;
    else if (ch == 4)
        cout << t - 273.15;
    else
        cout << "Invalid choice";
        
    return 0;
}
