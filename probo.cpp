#include <cmath>
#include <iostream>
#include <initializer_list>
#include <vector>
#include <algorithm>

//using namespace std;
using std :: cout;
using std :: cin;
namespace A {
    int value = 10;
    int data = 30;
}

void calculateCGPA() {
    int sum = 0;
    int count = 0;

    std :: vector <int> creadits {4, 3, 2, 1};
    std :: vector <std :: string> creadits {"CLA", "PIS", "TE", "ADD", "PSC", "TE(LAB)", "ADD(LAB)", "PSC(LAB)", "SS", "Tamil"};
    std :: vector <std :: string> grade {"O", "A+", "A", "B+", "B", "C", "P"};
    
    for(auto i = creadits.begin(); i != creadits.end(); ++ i, ++ count) {
        std :: string grd;
        int g_points = 0;
        cout << "Enter grade for " << *i << " : "; cin >> grd;
        int index = find(grade.begin(), grade.end(), grd) - grade.end();
        
        if(count <= 1) sum += (10 - index) * 4;
        else if(count <= )
        
    }

    cout << "____________ CGPA Calculator ______________";
    cout << "1.TE\n2.PSC\n3.PIS\n4.CLA\n5.ADD\n6.PSC(lab)\n7.EP(lab)\n8.SS\n9.Tamil";

}

namespace B {
    int value = 20;
}

void initialize(std :: initializer_list<int> list) {
    for(int element : list) {
        cout << element << "\n";
    }
}


int main() {
    unsigned int a = 5;
    //cout << ~a;

}

// ------------------------------------
// double temp, result;
// int choice;

// cout << "Temperature Converter\n1. Celsius to Fahrenheit\n2. Fahrenheit to Celsius\n3. Celsius "
//         "to Kelvin\nEnter choice (1-3): "; cin >> choice;
// cout << "Enter temperature value: "; cin >> temp;
// if (choice == 1) {
//     result = (temp * 9 / 5) + 32;
//     cout << temp << "C is " << result << "F" << endl;
// } else if (choice == 2) {
//     result = (temp - 32) * 5 / 9;
//     cout << temp << "F is " << result << "C" << endl;
// } else if (choice == 3) {
//     result = temp + 273.15;
//     cout << temp << "C is " << result << "K" << endl;
// } else {
//     cout << "Invalid choice." << endl;
// }