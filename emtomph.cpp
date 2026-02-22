#include <iostream>
#include <string>
#include <vector>

using namespace std;

// struct A {
//     int x, y;
// };

template <typename T>

T add(T a, T b) {
    return a + b;
}

class emtomph {
    public:
        emtomph() {
            cout << "Hello" << endl;
        }
};

int main(void) {
    ios ::sync_with_stdio(false);
    // cin.tie(nullptr);
    // vector <int> x;
    // x.push_back(1);
    // x.push_back(1);
    // x.push_back(1);
    // cout << x.size() << endl;
    // cout << x.capacity();
    // cout << add <int> (2, 3);
    // emtomph obj;
    int size;
    cout << "Enter :";
    cin >> size;
    vector<int> arr;
    vector<int> sum;
    for (int i = 0; i < size; i++) {
        int element;
        cin >> element;
        arr.push_back(element);
    }

    for (int i = 0; i < size / 2; i++)
        sum.push_back(arr[i] + arr[size - 1 - i]);

    for (decltype(size) i : sum)
        cout << i << "\n";

    return 0;
}
