#include <iostream>
#include <string>

using namespace std;

void display(const int * begin, const int * end) {
    for(; begin != end; ++begin) {
        cout << *begin << " ";
    }
}
int main(void) {
    ios :: sync_with_stdio(false);
    int arr[] {1, 2, 3, 4};
    
    // const int * ptr = arr;
    display(arr, arr + 4);
    // cout << end(arr) - begin(arr);
    return 0;
}