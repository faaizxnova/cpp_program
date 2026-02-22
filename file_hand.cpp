#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void) {
    string text;
    ifstream file("test.txt");

    while(getline(file, text))
        cout << text << endl;

    file.close();
}