#include <iostream>
#include "chap.h"

int fact(int num) {
    if(num == 1) return num;
    return num * fact(num - 1);
}