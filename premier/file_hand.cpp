#include <iostream>
#include <string>
#include "chap.h"

using namespace std;

void smp(int *& acn) {
    acn = nullptr;
}

int main(void) {
    ios :: sync_with_stdio(false);
    // cout << fact(5);
    int a = 10;
    int * p = &a;
    smp(p);
    if(p == nullptr) cout << "yes";
    return 0;
}