#include <iostream>
using namespace std;

int main() {
    float w, h;
    cout << "Weight(kg) Height(m): ";
    cin >> w >> h;

    float bmi = w / (h * h);
    cout << "BMI: " << bmi << endl;

    if (bmi < 18.5)
        cout << "Underweight";
    else if (bmi < 25)
        cout << "Normal";
    else if (bmi < 30)
        cout << "Overweight";
    else
        cout << "Obese";

    return 0;
}
