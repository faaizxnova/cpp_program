#include <string.h>

#include <iostream>

using namespace std;

int main(void) {
    int a, b;
    cout << "Enter number :";
    cin >> a >> b;
    try {
        if (b == 0)
            return -1;
        cout << "Result : " << a / b << endl;
    } catch (string e) {
        cout << e << endl;
    }
    return 0;
}