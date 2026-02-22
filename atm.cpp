#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

// using namespace std;
struct userDetails {
    std :: string name, pin, acc_num;
};

class atm {
    private:
        int bank_balance = 0;
        std :: string password;

    public:
        userDetails user_dat;
        int user_choice = 0, user_des = 0, amount = 0, bal = 0;
        std :: string user_name, account_number;
        bool is_valid = false;

        atm() {
            std :: cout << "\n-----------------------------------" << "\n";
            std :: cout << "           WELLCOME TO ATM";
            std :: cout << "\n-----------------------------------" << "\n";
            while (true) {
                std :: cout << "1.Pin \n2.Register Pin";
                std :: cout << "\nChoose your options : ";
                if ((std :: cin >> user_des) and (user_des == 1 or user_des == 2))
                    break;
                std :: cin.clear();
                std :: cin.ignore(1000, '\n');
                std :: cout << "\nInvalid Input!";
            }
        }

        void validateUser() {
            bool not_found = true;
            validateData(password, "Pin");
            std :: ifstream file("pass.dat");
            while (file >> user_dat.name >> user_dat.acc_num >> user_dat.pin >> bal) {
                if (user_dat.pin == password) {
                    is_valid = true;
                    not_found = false;
                    std :: cout << "\nlogin Successfull!";
                    break;
                }
            }

            if (not_found)
                std :: cout << "\nInvalid number or Not registered";

            file.close();
        }

        void validateData(std :: string &data, std ::string text) {
            while (true) {
                std :: cout << "\nEnter the " << text << " :";
                std ::cin >> data;
                if (text == "name" || data.length() == 6)
                    return;
                auto valid = [&](char c) { return isdigit(c); };

                if (data.length() == 4 && all_of(data.begin(), data.end(), valid))
                    return;
                std :: cout << "\nInvalid " << text << "!";
            }
        }

        void registerPin() {
            validateData(account_number, "Account Number");
            validateData(user_name, "name");
            validateData(password, "pin");
            
            std :: ofstream file("pass.dat", std :: ios :: app);
            file << user_name << " " << account_number << " " << password << " 0\n";
            std :: cout << "PIN registered successfully!";
            file.close();
        }

        void Options() {
            std :: cout << "\n-----------------------------------" << "\n";
            std :: cout << "           CHOOSE";
            std :: cout << "\n-----------------------------------" << "\n";
            std :: cout << "\n1.Withdraw \n2.Deposite \n3.Change Pin \n4.Display Balance \n5.Exit\n";
            std :: cout << "Choose your options : ";
            std :: cin >> user_choice;
        }

        void updateFile() {
            std :: string result;
            std :: ifstream inFile("pass.dat");

            while (inFile >> user_dat.name >> user_dat.acc_num >> user_dat.pin >> bal) {
                if (user_dat.pin == password)
                    result += user_dat.name + " " + user_dat.acc_num + " " +
                              user_dat.pin + " " + std :: to_string(bank_balance) + "\n";
                else
                    result += user_dat.name + " " + user_dat.acc_num + " " +
                              user_dat.pin + " " + std :: to_string(bal) + "\n";
            }
            inFile.close();

            std :: ofstream outFile("pass.dat", std :: ios :: trunc);
            outFile << result;
            outFile.close();
        }

        void Withdraw() {
            std :: cout << "Enter the amount :";
            while (true) {
                if (std :: cin >> amount)
                    break;
                else
                    std :: cout << "\nInvalid Amount!";
            }

            std :: ifstream inFile("pass.dat");
            while (inFile >> user_dat.name >> user_dat.acc_num >> user_dat.pin >> bal)
                if (user_dat.pin == password)
                    bank_balance = bal;
            inFile.close();

            if (amount <= 0 || amount > bank_balance) {
                std :: cout << "\nInsufficient Amount ! or Invalid Amount!";
                return;
            }
            bank_balance -= amount;
            updateFile();
            std :: cout << amount << " Rs " << "Amount Withdraw Successfull!";
        }

        void Deposite() {
            std :: cout << "\nEnter the amount :";
            while (true) {
                if (std :: cin >> amount)
                    break;
                else
                    std :: cout << "\nInvalid Amount!";
            }

            std :: ifstream inFile("pass.dat");
            while (inFile >> user_dat.name >> user_dat.acc_num >> user_dat.pin >> bal)
                if (user_dat.pin == password)
                    bank_balance = bal;
            inFile.close();

            bank_balance += amount;
            updateFile();
            std :: cout << amount << " Rs " << "Amount Deposited Successfull!";
        }

        bool isExist(std :: string n_pin) {
            std :: ifstream inFile("pass.dat");
            while (inFile >> user_dat.name >> user_dat.acc_num >> user_dat.pin >> bal)
                if (n_pin == user_dat.pin)
                    return true;
            return false;
        }

        void changePin() {
            bool found = false, execute = true;
            std ::string result, current_pin, new_pin;
            std :: cout << "\nEnter the current pin : ";
            std :: cin >> current_pin;

            std :: ifstream inFile("pass.dat");
            if (!inFile) {
                std :: cout << "\nError opening file!";
                return;
            }

            while (inFile >> user_dat.name >> user_dat.acc_num >> user_dat.pin >> bal) {
                if (current_pin == user_dat.pin) {
                    validateData(new_pin, "New Pin");

                    if (isExist(new_pin)) {
                        std :: cout << "\nPin Already Exist!";
                        return;
                    } else {
                        found = true;
                        execute = false;
                        password = new_pin;
                        result += user_dat.name + " " + user_dat.acc_num + " " +
                                  new_pin + " " + std :: to_string(bal) +
                                  "\n";
                    }
                }
            }
            if (execute) {
                std :: cout << "Pin not found!";
                result += user_dat.name + " " + user_dat.acc_num + " " +
                          user_dat.pin + " " + std :: to_string(bal) + "\n";
            }
            inFile.close();

            std :: ofstream outFile("pass.dat", std :: ios :: trunc);
            outFile << result;
            outFile.close();

            if (found)
                std :: cout << "\nPIN changed successfully!";
            return;
        }

        void displayBalance() {
            std :: ifstream inFile("pass.dat");

            while (inFile >> user_dat.name >> user_dat.acc_num >> user_dat.pin >> bal) {
                if (user_dat.pin == password)
                    std :: cout << "Balance Amount : " << bal;
            }
            inFile.close();
        }
};

int main(void) {
    std :: ios :: sync_with_stdio(false);
    atm obj;
    if (obj.user_des == 2)
        obj.registerPin();
    while (!obj.is_valid)
        obj.validateUser();
    while (true) {
        obj.Options();
        if (obj.user_choice == 1)
            obj.Withdraw();
        else if (obj.user_choice == 2)
            obj.Deposite();
        else if (obj.user_choice == 3)
            obj.changePin();
        else if (obj.user_choice == 4)
            obj.displayBalance();
        else if (obj.user_choice == 5)
            return 0;
        else
            std :: cout << "\nInvalid Input!";
    }
    return 0;
}