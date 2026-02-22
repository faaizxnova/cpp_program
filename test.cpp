#include <cstdio>
#include <iostream>
using namespace std;

class Solution {
    int a;
    long long int b;
    char c;
    float d;
    double e;

    public:
        Solution(int a, long long b, char c, float d, double e) {
            this->a = a;
            this->b = b;
            this->c = c;
            this->d = d;
            this->e = e;
        }

        void result() {
            cout << a << endl << b << endl << c << endl << d << endl << e << endl;
        }
};

int main() {
    int a;
    long long int b;
    char c;
    float d;
    double e;
    cin >> a >> b >> c >> d >> e;
    Solution sol(a, b, c, d, e);
    sol.result();
    return 0;
}
