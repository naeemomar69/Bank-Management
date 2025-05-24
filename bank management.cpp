#include <iostream>
#include <vector>
#include <string>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    string accountHolder;
    float balance;

public:
    BankAccount(int accNo, string holder, float initialBalance) {
        accountNumber = accNo;
        accountHolder = holder;
        balance = initialBalance;
    }

    void deposit(float amount) {
        balance += amount;
        cout << "Amount deposited successfully.\n";
    }

    void withdraw(float amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance.\n";
        }
    }

    void showAccount() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};

vector<BankAccount> accounts;

BankAccount* findAccount(int accNo) {
    for (auto &account : accounts) {
        if (account.getAccountNumber() == accNo) {
            return &account;
        }
    }
    return nullptr;
}

void createAccount() {
    int accNo;
    string holder;
    float balance;

    cout << "Enter Account Number: ";
    cin >> accNo;
    cout << "Enter Account Holder Name: ";
    cin.ignore();
    getline(cin, holder);
    cout << "Enter Initial Balance: $";
    cin >> balance;

    accounts.push_back(BankAccount(accNo, holder, balance));
    cout << "Account created successfully!\n";
}

void showAllAccounts() {
    for (const auto &account : accounts) {
        account.showAccount();
        cout << "------------------\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n==== Bank Management System ====\n";
        cout << "1. Create New Account\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Account Details\n";
        cout << "5. View All Accounts\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 6) break;

        int accNo;
        float amount;
        BankAccount *account;

        switch (choice) {
            case 1:
                createAccount();
                break;

            case 2:
                cout << "Enter Account Number: ";
                cin >> accNo;
                account = findAccount(accNo);
                if (account) {
                    cout << "Enter Amount to Deposit: $";
                    cin >> amount;
                    account->deposit(amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;

            case 3:
                cout << "Enter Account Number: ";
                cin >> accNo;
                account = findAccount(accNo);
                if (account) {
                    cout << "Enter Amount to Withdraw: $";
                    cin >> amount;
                    account->withdraw(amount);
                } else {
                    cout << "Account not found.\n";
                }
                break;

            case 4:
                cout << "Enter Account Number: ";
                cin >> accNo;
                account = findAccount(accNo);
                if (account) {
                    account->showAccount();
                } else {
                    cout << "Account not found.\n";
                }
                break;

            case 5:
                showAllAccounts();
                break;

            default:
                cout << "Invalid choice!\n";
        }
    }

    cout << "Thank you for using Bank Management System.\n";
    return 0;
}

