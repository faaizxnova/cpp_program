#include <iostream>
#include <string>
using namespace std;

typedef int (*Operation) (int, int);

int add(int x, int y) {
    return x + y;
}

int mul(int x, int y) {
    return x * y;
}


int main(void) {
    // int num, dum;
    // if(((cin >> num) and (cin >> dum)) and num > 0 and dum > 0) 
    //     cout <<"yes";
    // int i = 10, j = 20;
    // int &r = i;
    // r = j;
    // cout << i;
    // int a = 1;
    // const int &x = a * 2;
    // int &x = a * 2 error : plane : not be expression;
    // cout << x;
    // int b = 2, c;
    // const int *const p = &b;
    //const int  &const a = b;
    //cout << a;
    Operation op;
    op = add;
    op = mul;
    cout << op(2, 4);
    return 0;
}