#include <iostream>
#define CALL_ERR_POS "Enter a positive number!"
#define LNGINT signed long long int

using namespace std;

class Matho {
    public:
        Matho() {
            cout << "\n---------------------------------------\n";
            cout << "             WELLCOME TO MATHO\n";
            cout << "-----------------------------------------\n";
        }

        void getNumber(LNGINT &number) {
            cout << "\nEnter a number :"; 
            cin >> number;
        }

        void MENU(int &user_choice) {
            cout << "\n----------------------------------\n";
            cout << "               MENU\n";
            cout << "----------------------------------\n";
            cout << "1.Reverse\n2.Sum of Digits\n3.Check Palindrom\n4.Exit\nChoose :";
            cin >> user_choice;
        }

        LNGINT reverse(LNGINT &number) {
            LNGINT rev = 0, cpy = number;
            bool sign = true;
            if(number < 0) {
                cpy = -cpy;
                bool sign = false;
            }
            while(cpy) {
                rev = rev * 10 + cpy % 10;
                cpy /= 10;
            }
            return sign ? rev : -rev;
        }

        LNGINT sumOfDigits(LNGINT &number) {
            LNGINT sum = 0, cpy = number;
            while(cpy) {
                sum += cpy % 10;
                cpy /= 10;
            }
            return sum;
        }

        bool isPalindrome(LNGINT &number) {
            if(reverse(number) == number) return true;
            return false;
        }

        ~Matho() {
            cout << "\nThank you for visiting!";
        }
};

int main(void) {
    Matho math;
    LNGINT number = 0;
    int user_choice = 0, rev = 0, sum = 0;
    while (true) {
        math.MENU(user_choice);
        if (user_choice == 1) {
            math.getNumber(number);
            rev = math.reverse(number);
            cout << "\nReverse of the number " << number << " is " << rev;
        } else if (user_choice == 2) {
            math.getNumber(number);
            if (number < 0) {
                printf(CALL_ERR_POS);
                return 0;
            }
            sum = math.sumOfDigits(number
            
            );
            cout << "Sum of digits of the number " << number << " is " << sum;
        } else if (user_choice == 3) {
            math.getNumber(number);
            if (math.isPalindrome(number))
                cout << "\nThe given number " << number << " is palindrom";
            else
                cout << "\nThe given number " << number << " is not palindrom";
        } else if (user_choice == 4) return 0;
        else
            cout << "\nInvalid choice!";
    }
}