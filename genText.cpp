#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    string sentance = "";
    cout << "Enter code :";
    getline(cin, input);
    for(int i = 1; i < input.length(); i += 4) {
        string octalPart = input.substr(i, 3);
        int decimalValue = stoi(octalPart, nullptr, 8); 
        sentance += static_cast<char>(decimalValue);
    }
    cout << sentance;

}