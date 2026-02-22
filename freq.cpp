#include <iostream>
#include <string>

using namespace std;

int main(void) {
    int cval = 0, val = 0;
    if(cin >> cval) {
        int count = 1;
        while(cin >> val) {
            if(cval == val) 
                ++ count;
            
            else {
                cout << cval << count << endl;
                cval = val;
                count = 1;
            }
        }
    }
}