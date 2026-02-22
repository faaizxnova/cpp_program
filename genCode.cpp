#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(void) {
    string input, slash = "\\", code = "";
    cout << "Enter a sentence :";
    getline(cin, input);
    for (int i : input) {
        string octalStr;
        stringstream octal;
        octal << oct << i;
        octal >> octalStr;
        string n_code = (i == 32) ? "0" + octalStr : octalStr;
        code = slash + n_code;
        cout << code;
    }
}