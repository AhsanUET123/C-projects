#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    double balance;
    string pin;
    string name;
    bool isDefaultBank;

public:
    Account(double initialBalance = 0.0, string initialPin = "1234", string initialName = "", bool defaultBank = true) 
        : balance(initialBalance), pin(initialPin), name(initialName), isDefaultBank(defaultBank) {}

    void displayBalance() {
        cout << "Current Balance: $" << balance << endl;
    }

    void withdraw() {
        int choice;
        cout << "Withdrawal Options:" << endl;
        cout << "1. $100" << endl;
        cout << "2. $200" << endl;
        cout << "3. $500" << endl;
        cout << "4. Other amount" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        double amount;
        switch (choice) {
            case 1:
                amount = 100.0;
                break;
            case 2:
                amount = 200.0;
                break;
            case 3:
                amount = 500.0;
                break;
            case 4: {
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                break;
            }
            default:
                cout << "Invalid option. Try again!" << endl;
                return;
        }

        if (amount > 25000) {
            cout << "Transaction not allowed. Maximum withdrawal per transaction is $25000." << endl;
            return;
        }

        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            if (!isDefaultBank) {
                double taxAmount = 50.00;
                balance -= taxAmount;
                cout << "Withdrawal successful. Tax of $" << taxAmount << " has been cut. New balance: $" << balance << endl;
            } else {
                cout << "Withdrawal successful. New balance: $" << balance << endl;
            }

            char receiptOption;
            cout << "Would you like to generate a receipt? (y/n): ";
            cin >> receiptOption;

            if (receiptOption == 'y' || receiptOption == 'Y') {
                cout << "Receipt:" << endl;
                cout << "Withdrawal Amount: $" << amount << endl;
                cout << "New Balance: $" << balance << endl;
                cout << "Date: "  << endl;
                cout << "Time: "  << endl;
            } else {
                cout << "Thank you for choosing to go green! You're helping to reduce paper waste." << endl;
                cout << "Here's a virtual tree to celebrate your eco-friendly choice:" << endl;
            }
        }
    }

    void deposit() {
        double amount;
        cout << "Enter deposit amount: $";
        cin >> amount;

        balance += amount;
        cout << "Deposit successful. New balance: $" << balance << endl;
    }

    bool authenticate(string enteredPin) {
        return pin == enteredPin;
    }

    void setPin(string newPin) {
        pin = newPin;
    }

    void setDefaultBank(bool defaultBank) {
        isDefaultBank = defaultBank;
    }

    string getName() {
        return name;
    }
};

int main() {
    Account account1(50000.0, "1234", "Engr.Aimal khan", true); // default bank account
    Account account2(60000.0, "5678", "Engr.Ashar Amir", false); // non-default bank account
    Account account3(70000.0, "9012", "Engr.Ahsan", false); // non-default bank account

    Account* accounts[] = {&account1, &account2, &account3};
    string pins[] = {"1234", "5678", "9012"};
    string names[] = {"Engr.Aimal khan", "Engr.Ashar Amir", "Engr.Ahsan"};

    string enteredPin;
    cout << "Enter your PIN: ";
    cin >> enteredPin;

    bool authenticated = false;
    Account* selectedAccount = nullptr;

    for (int i = 0; i < 3; i++) {
        if (pins[i] == enteredPin) {
            authenticated = true;
            selectedAccount = accounts[i];
            break;
        }
    }

    if (!authenticated) {
        cout << "Invalid PIN. Try again!" << endl;
        return 1;
    }

    cout << "Welcome, " << selectedAccount->getName() << "!" << endl;

    int option;
    do {
        cout << "HBL ATM " << endl;
        cout << "1. Balance Inquiry" << endl;
                cout << "2. Withdrawal" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        switch (option) {
            case 1:
                selectedAccount->displayBalance();
                break;
            case 2:
                selectedAccount->withdraw();
                break;
            case 3:
                selectedAccount->deposit();
                break;
            case 4:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Try again!" << endl;
        }
    } while (option != 4);

    return 0;
}
