#include <iostream>
using namespace std;

int main() {
    int n, m, sum = 0;
    cout << "No of subjects: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m;
        sum += m;
    }

    double avg = sum / (double)n;
    cout << "Total: " << sum << "\nAverage: " << avg << endl;

    if (avg >= 90)
        cout << "Grade A";
    else if (avg >= 75)
        cout << "Grade B";
    else if (avg >= 60)
        cout << "Grade C";
    else
        cout << "Grade D";

    return 0;
}
