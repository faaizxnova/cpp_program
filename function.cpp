#include <iostream>
#include <cstdio>
using namespace std;

class Solution {
    public:
        int b, c, d, max;
        Solution(int a, int b, int c, int d) {
            this -> max = a;
            this -> b = b;
            this -> c = c;
            this -> d = d;
        }

        int max_of_four() {
           if(b > max) max = b;
           if(c > max) max = c;
           if(d > max) max = d;
           return max;
        }
};

int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    Solution sol(a, b, c, d);
    int result = sol.max_of_four();
    printf("%d", result);
    return 0;
}