#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    char a = 'A', b = 'a';
    if(a == b) cout << "t";
    return 0;
}

// ----------------------------
// int n;
// cout << "Enter a number : ";
// cin >> n;
// cout << "Bit AND : " << (n & 1) << "\n"
//      << "Bit OR : " << (n | 1) << "\n"
//      << "Bit XOR : " << (n ^ 1) << "\n"
//      << "Left Swift : " << (n << 1) << "\n"
//      << "Right Shift : " << (n >> 1) << "\n";
// cout << ((n & 1) ? "Odd" : "Even");
// ------------------------------
// int n;
// cout << "Enter a number : ";
// cin >> n;
// cout << "Digital Root : " << (n ? 1 + (n - 1) % 9 : n);
// -----------------------------
// int num = 0, rev = 0;
// cout << "Enter a Number : "; cin >> num;
// while(num) rev = rev * 10 + num % 10, num /= 10;
// cout << "Reversed Number : " << rev;
// -----------------------------
// vector<string> st {"hi", "hello", "wellcome"};
// for(auto it = st.datain(); it != st.end() && !it -> empty(); ++ it){
//     cout << *it << "\n";
// }
// int i = 0, j = 2;
// if(i || (j = 6)); cout << i << " " << j;
// int a = 3, b = 7;
// a == b == 5;
// cout << a << " " << b;