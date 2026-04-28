#include<iostream>

using namespace std;

class bank_account {
    char Account_Holder_Name[200];
    double Accn;
    long double Account_balance;

public:
    void create_account();
    void display_balance();

    int search_acc(double search_id);
    void withdraw_money();
    void deposite_money();
};

void bank_account::create_account() {
    cout << "Enter the account holder name: ";
    cin >> Account_Holder_Name;
    cout << "Enter the account number: ";
    cin >> Accn;
    cout << "Enter initial account balance: ";
    cin >> Account_balance;
    cout << "Account created successfully!" << endl;
}

void bank_account::display_balance()
{
    cout << "Holder Name: " << Account_Holder_Name << endl;
    cout << "Balance    : " << Account_balance << endl;
}

int bank_account::search_acc(double search_id) {
    if (Accn == search_id) {
        return 1;
    }
    return 0;
}

void bank_account::withdraw_money() {
    long double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;
    if (amount > Account_balance) {
        cout << "Insufficient balance." << endl;
    } else {
        Account_balance -= amount;
        cout << "Withdrawal successful. Current balance: " << Account_balance << endl;
    }
}

void bank_account::deposite_money() {
    long double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;
    Account_balance += amount;
    cout << "Deposit successful. Current balance: " << Account_balance << endl;
}

int main() {
    bank_account B[50];
    int choice, account_count = 0;
    double search_id;


options:
        cout << "\n1. Deposit money\n2. Withdraw money\n3. Check Balance\n4. Create Account\n5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;



        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> search_id;
              for (int i = 0; i < account_count; i++) {
                    if (B[i].search_acc(search_id) == 1) {
                        B[i].deposite_money();
                        }
                        else
                        {
                            cout<<"Invalid Account Number"<<endl;
                        }
}

goto options;


            case 2:
                cout << "Enter account number: ";
                cin >> search_id;

                for (int i = 0; i < account_count; i++) {
                    if (B[i].search_acc(search_id) == 1) {
                        B[i].withdraw_money();

                   }
                    else{
                        cout<<"Invalid Account Number";
                    }
                }
                  goto options;

            case 3:
                cout << "Enter account number: ";
                cin >> search_id;

                for (int i = 0; i < account_count; i++) {
                    if (B[i].search_acc(search_id) == 1) {
                        B[i].display_balance();

                    }
                    else{
                        cout<<"Invalid Account Number";
                    }
                }
                  goto options;

            case 4:
                if (account_count < 50) {
                    B[account_count].create_account();
                    account_count++;
                } else {
                    cout << "Limit reached. Cannot create more accounts." << endl;
                }


            goto options;
        }


    return 0;

}
