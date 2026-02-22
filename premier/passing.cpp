#include <iostream>
#include <string>

using namespace std;

void display(const int * begin, const int * end) {
    for(; begin != end; ++begin) {
        cout << *begin << " ";
    }
}
int main(int argc, char ** argv) {
    ios :: sync_with_stdio(false);
    // int arr[] {1, 2, 3, 4};
    // const int * ptr = arr;
    // display(arr, arr + 4);
    // cout << end(arr) - begin(arr);
    // int * arr[2];
    // for(int i = 0; i < 2; ++ i) {
    //     int sub[2];
    //     for(int j = 0; j < 2; ++ j) {
    //         cout << "Enter elements : "; cin >> sub[j];
    //     }
    //     arr[i] = sub;
    // }

    // for (int i = 0; i < 2; ++i) {
    //     for (int j = 0; j < 2; ++j) {
    //         cout << *arr[i] ++;
    //     }
    //     cout << '\n';
    // }

    cout << atoi(argv[1]) + atoi(argv[2]);
    return 0;
}