#include <iostream>
#include <unordered_map>
using namespace std;

class BankAccount {
private:
    string name;
    double balance;

public:
    BankAccount(string n, double bal){
        name=n;
        balance=bal;
    }


    string getName() const {
        return name;
    }

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        cout << "\t\tInsufficient Balance...." << endl;
        return false;
    }
};

class BankManagement {
private:
    unordered_map<int, BankAccount> accounts;

public:
    void AddAccount(string name, int accountNum, double balance) {
        accounts.insert({accountNum, BankAccount(name, balance)});
    }

    void showAllAccounts() {
        cout << "\t\tAll Account Holders " << endl;
        for (const auto& entry : accounts) {
            cout << "\t\tName: " << entry.second.getName()
                 << " Account Number: " << entry.first
                 << " Balance: " << entry.second.getBalance() << endl;
        }
    }

    void searchAccount(int accountNum) {
        auto it = accounts.find(accountNum);
        if (it != accounts.end()) {
            cout << "\t\tAccount Holder " << endl;
            cout << "\t\tName: " << it->second.getName()
                 << " Account Number: " << it->first
                 << " Balance: " << it->second.getBalance() << endl;
        } else {
            cout << "\t\tAccount Not Found ..." << endl;
        }
    }

    bool deposit(int accountNum, double amount) {
        auto it = accounts.find(accountNum);
        if (it != accounts.end()) {
            it->second.deposit(amount);
            cout << "\t\t" << amount << " Deposit Successfully ...." << endl;
            return true;
        } else {
            cout << "\t\tAccount Not Found ..." << endl;
            return false;
        }
    }

    bool withdraw(int accountNum, double amount) {
        auto it = accounts.find(accountNum);
        if (it != accounts.end()) {
            it->second.withdraw(amount);
             cout << "\t\t" << amount << " Withdrawn Successfully ...." << endl;
            return true;
        } else {
            cout << "\t\tAccount Not Found ..." << endl;
            return false;
        }
    }
};

int main() {
    BankManagement bank;
    int choice;
    char op;
    do {
        system("cls");
        cout << "\t\t::Bank Management System" << endl;
        cout << "\t\t\tMain Menu" << endl;
        cout << "\t\t1. Create New Account" << endl;
        cout << "\t\t2. Show All Accounts" << endl;
        cout << "\t\t3. Search Account" << endl;
        cout << "\t\t4. Deposit Money" << endl;
        cout << "\t\t5. Withdraw Money" << endl;
        cout << "\t\t6. Exit" << endl;
        cout << "\t\t-------------------------------" << endl;
        cout << "\t\tEnter Your Choice :";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int accountNum;
                double balance;
                cout << "\t\tEnter Name: ";
                cin.ignore();
                getline(cin,name);
                cout << "\t\tEnter Account Number: ";
                cin >> accountNum;
                cout << "\t\tEnter Initial Balance: ";
                cin >> balance;
                bank.AddAccount(name, accountNum, balance);
                cout << "\t\tAccount Created Successfully...." << endl;
                break;
            }
            case 2: {
                bank.showAllAccounts();
                break;
            }
            case 3: {
                int accountNum;
                cout << "\t\tEnter Account Number: ";
                cin >> accountNum;
                bank.searchAccount(accountNum);
                break;
            }
            case 4: {
                int accountNum;
                double amount;
                cout << "\t\tEnter Account Number to Deposit Money: ";
                cin >> accountNum;
                cout << "\t\tEnter Amount to Deposit: ";
                cin >> amount;
                bank.deposit(accountNum, amount);
                break;
            }
            case 5: {
                int accountNum;
                double amount;
                cout << "\t\tEnter Account Number to Withdraw Money: ";
                cin >> accountNum;
                cout << "\t\tEnter Amount to Withdraw: ";
                cin >> amount;
                bank.withdraw(accountNum, amount);
                break;
            }
            case 6: {
                exit(1);
                break;
            }
        }
        cout << "\t\tDo You Want to Continue or Exit [Yes/No] ??";
        cin >> op;

    } while (op == 'y' || op == 'Y');

    return 0;
}
