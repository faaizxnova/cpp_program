#include <cmath>
#include <iostream>
using namespace std;

int main() {
    double p, r, t;
    cout << "Enter P R T: ";
    cin >> p >> r >> t;

    double si = (p * r * t) / 100;
    double ci = p * pow(1 + r / 100, t) - p;

    cout << "Simple Interest: " << si << endl;
    cout << "Compound Interest: " << ci;
    return 0;
}