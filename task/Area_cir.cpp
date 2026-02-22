#include <iostream>
using namespace std;

int main() {
    const float PI = 3.14159;
    float r;
    cout << "Enter radius: ";
    cin >> r;

    cout << "Area: " << PI * r * r << endl;
    cout << "Circumference: " << 2 * PI * r;
    return 0;
}
