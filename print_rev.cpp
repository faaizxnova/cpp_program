#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int num;
        int* array_;
        Solution(int* array_, int num) {
            this->array_ = array_;
            this->num = num;
        }

        void printReverse() {
            for (int i = num - 1; i >= 0; i--) {
                cout << array_[i] << " ";
            }
        }
};

int main() {
    unsigned short int num;
    cin >> num;
    int array_[num];
    for (int i = 0; i < num; i++)
        cin >> array_[i];
    Solution sol(&array_[0], num);
    sol.printReverse();
    return 0;
}
