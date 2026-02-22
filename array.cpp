#include <iostream>
#include <vector>
using namespace std;

float findAverage(vector<int> &arr) {
    int sum = 0;
    for (int i = 1; i < arr.size(); i++) {  
        sum += arr[i];
    }
    return sum / arr.size();
}

int main() {
    vector<int> marks = {80, 90, 75, 85};
    float avg = findAverage(marks);
    cout << "Average = " << avg << endl;
    return 0;
}
