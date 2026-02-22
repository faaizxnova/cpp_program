
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

typedef int* Intptr;

class food_menu {
    private:
        string username, password;

    public:
        Intptr choise, ID;
        int quantity = 0, amount = 0, multipiler = 0, refund = 0;
        char type;
        bool is_placed = false, *is_login;
        vector<string> types{"small", "medium", "large"};

        food_menu(Intptr choise, Intptr ID, bool *is_login) {
            this -> choise = choise;
            this -> ID = ID;
            this -> is_login = is_login;
        }

        void getUserOption() {
            cout << "\n-----------------------------------" << "\n";
            cout << "     WELLCOME TO FOOD ORDERING" << "\n";
            cout << "-----------------------------------" << "\n";
            cout << "\n1.Menu \n2.Proceed Order \n3.Cancel Order \n4.Display Amount \n5.Exit\n";
            cout << "Choose your options : ";
            cin >> *choise;
        }

        int loginValidation() {
            int option = 0;
            cout << "\n-----------------------------------" << "\n";
            cout << "               LOGIN";
            cout << "\n-----------------------------------" << "\n";
            cout << "\n1.Login  \n2.Sign Up \n3.Exit";
            cout << "\nEnter (1 | 2 | 3):";
            cin >> option;
            return option;
        }

        void login() {
            string file_user, file_pass;
            cout << "Enter username :";
            cin >> username;
            cout << "Enter password :";
            cin >> password;
            ifstream file("user.dat");
            if(!file) {
                cout << "\nNo User Found!";
                return;
            }
            while(file >> file_user >> file_pass) {
                if(file_user == username and file_pass == password) {
                    *is_login = true;
                    break;
                }
            }
            file.close();

            if (*is_login)
                cout << "\nLogin Successfull!";
            else
                cout << "\nInvalid Username or Password!";
        }

        void signUp() {
            cout << "\n---- Create Username and Password ----";
            cout << "Enter username :";
            cin >> username;
            cout << "Enter password :";
            cin >> password;
            ofstream file("user.dat", ios :: app);
                if(!file) {
                    cout << "\nError Opening File!";
                    return;
                }
                file << username << " " << password << endl;
                file.close();
                cout << "\nSign Up Successfully!";
        }

        void displayMenu() {
            cout << "\n-----------------------------------" << "\n";
            cout << "               MENU" << "\n";
            cout << "-----------------------------------" << "\n";
            cout << "\n1.Pizza \n2.Burger \n3.KFC \n4.Exit \n";
            cout << "Enter the food ID :";
            cin >> *ID;
        }

        void displayFoodDeatils() {
            for (int i = 0; i < types.size(); i++)
                cout << "\n" << types.at(i) << " (cost) " << ": " << (i + 1) * 100 * *ID << " Rs ";
            cout << "\nEnter type :";
            cin >> type;
            cout << "Enter quantity :";
            cin >> quantity;
        }

        void calculateAmount() {
            multipiler = 0;
            for (int i = 0; i < types.size(); i++)
                if (types.at(i)[0] == type)
                    multipiler = (i + 1) * 100 * (*ID);
            amount += multipiler * quantity;
        }
        void placeOrder() {
            is_placed = true;
            cout << "Order Placed Successfully!\n";
        }

        void showAmount() {
            if (is_placed)
                cout << "Total amount : " << amount << "\n";
            else
                cout << "\nPlaced the order first!";
        }

        void cancelOrder() {
            if (amount > 0) {
                refund += multipiler * quantity;
                amount -= multipiler * quantity;
                cout << "Order Canceled Successfully!\n";
                cout << "\nAmount refunded :" << refund;
            } else
                cout << "\nNo food oerdered yet!";
        }

        ~food_menu() {
            cout << "Thank you for visiting !";
        }
};

int main(void) {
    ios ::sync_with_stdio(false);
    int choise = 0, ID = 0;
    bool is_login = false;
    food_menu obj(&choise, &ID, &is_login);

    while (!is_login) {
        int option = obj.loginValidation();
        if ( option == 1) obj.login();
        else if ( option == 2) obj.signUp();
        else if ( option == 3) return 0;
        else cout << "\nInvalid Input!";
    }

    while (true) {
        obj.getUserOption();
        switch (choise) {
            case 1:
                obj.displayMenu();
                obj.displayFoodDeatils();
                obj.calculateAmount();
                break;

            case 2:
                obj.placeOrder();
                break;

            case 3:
                obj.cancelOrder();
                break;

            case 4:
                obj.showAmount();
                break;

            case 5:
                return 0;
        }
    }
    return 0;
}