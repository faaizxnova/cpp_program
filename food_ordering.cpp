#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class UserAuth {
    public:
        bool login() {
            string u, p, fu, fp;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;

            ifstream file("user.dat");
            while (file >> fu >> fp) {
                if (u == fu && p == fp)
                    return true;
            }
            return false;
        }

        void signup() {
            string u, p;
            cout << "New Username: ";
            cin >> u;
            cout << "New Password: ";
            cin >> p;

            ofstream file("user.dat", ios::app);
            file << u << " " << p << '\n';
            cout << "Signup successful!\n";
        }
};

class Menu {
    public:
        int selectFood() {
            int id;
            cout << "\n1.Pizza\n2.Burger\n3.KFC\nChoice: ";
            cin >> id;
            return id;
        }

        int selectSize(int foodID) {
            const int base = 100;
            cout << "\n1.Small\n2.Medium\n3.Large\nChoice: ";
            int size;
            cin >> size;
            return size * base * foodID;
        }
};

class Order {
    private:
        int amount = 0;

    public:
        void add(int price, int qty) {
            amount += price * qty;
        }

        void cancel(int price, int qty) {
            amount -= price * qty;
            cout << "Order canceled!\n";
        }

        void show() const {
            cout << "Total Amount: " << amount << " Rs\n";
        }
};

int main() {
    UserAuth auth;
    Menu menu;
    Order order;

    int option;
    while (true) {
        cout << "\n1.Login\n2.Signup\n3.Exit\nChoice: ";
        cin >> option;

        if (option == 1 && auth.login())
            break;
        else if (option == 2)
            auth.signup();
        else if (option == 3)
            return 0;
        else
            cout << "Invalid!\n";
    }

    while (true) {
        cout << "\n1.Menu\n2.Show Amount\n3.Exit\nChoice: ";
        cin >> option;

        if (option == 1) {
            int food = menu.selectFood();
            int price = menu.selectSize(food);
            int qty;
            cout << "Quantity: ";
            cin >> qty;
            order.add(price, qty);
        } else if (option == 2)
            order.show();
        else
            return 0;
    }
}
