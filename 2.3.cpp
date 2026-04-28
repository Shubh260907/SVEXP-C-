#include <iostream>
#include <string>

using namespace std;

class DigitalAccount {
private:
    string customerName;
    int accountID;
    double balance;

public:
    DigitalAccount() {
        customerName = "N/A";
        accountID = 0;
        balance = 0.0;
    }

    DigitalAccount(string name, int id, double initialDeposit) {
        customerName = name;
        accountID = id;
        balance = (initialDeposit >= 0) ? initialDeposit : 0.0;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << " into ID: " << accountID << endl;
        } else {
            cout << "Error: Deposit amount must be positive." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Error: Invalid withdrawal amount." << endl;
        } else if (amount > balance) {
            cout << "Transaction Declined: Insufficient funds for ID: " << accountID << endl;
            cout << "Attempted: $" << amount << " | Available: $" << balance << endl;
        } else {
            balance -= amount;
            cout << "Successfully withdrawn $" << amount << " from ID: " << accountID << endl;
        }
    }

    void displaySummary() const {
        cout << "--- Account Summary ---" << endl;
        cout << "ID: " << accountID << " | Name: " << customerName << endl;
        cout << "Current Balance: $" << balance << endl;
        cout << "-----------------------" << endl;
    }
};

int main() {
    const int TOTAL_ACCOUNTS = 2;
    DigitalAccount accounts[TOTAL_ACCOUNTS];

    accounts[0] = DigitalAccount("Sarah Connor", 1001, 500.0);
    accounts[1] = DigitalAccount("John Doe", 1002, 50.0);

    accounts[0].deposit(250.0);
    accounts[1].withdraw(100.0);
    accounts[0].withdraw(100.0);

    for (int i = 0; i < TOTAL_ACCOUNTS; i++) {
        accounts[i].displaySummary();
    }

    return 0;
}
