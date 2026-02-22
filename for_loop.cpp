#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
    public:
        int num;
        vector<string> num_name = {"one", "two",   "three", "four", "five",
                                   "six", "seven", "eight", "nine"};

        Solution(int n) {
            this->num = n;
        }

        void printNumber() {
            cout << num_name[num - 1] << endl;
        }

        void OddorEven() {
            cout << ((num bitand 1) ? "odd" : "even") << endl;
        }
};

int main() {
    int a, b;
    if (!(cin >> a >> b))
        return 0;

    for (; a <= b; a++) {
        Solution sol(a);
        if (a <= 9)
            sol.printNumber();
        else
            sol.OddorEven();
    }
    return 0;
}