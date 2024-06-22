#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    double balance;
    string pin;
    bool isDefaultBank;

public:
    Account(double initialBalance = 0.0, string initialPin = "1234", bool defaultBank = true) : balance(initialBalance), pin(initialPin), isDefaultBank(defaultBank) {}

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

        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            if (!isDefaultBank) {
                double taxAmount = amount * 0.10;
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
};

int main() {
    cout << "Welcome to HBL Banking" << endl;
    Account account(1000.0, "1234"); // initial balance of $1000 and PIN 1234

    string enteredPin;
    bool authenticated = false;

    do {
        cout << "Enter your PIN: ";
        cin >> enteredPin;

        if (account.authenticate(enteredPin)) {
            authenticated = true;
        } else {
            cout << "Invalid PIN. Try again!" << endl;
        }
    } while (!authenticated);

    char isDefault;
    cout << "Are you a HBL bank customer? (y/n): ";
    cin >> isDefault;

    if (isDefault == 'y' || isDefault == 'Y') {
        account.setDefaultBank(true);
    } else {
        account.setDefaultBank(false);
    }

    int choice;
    do {
        cout << "HBL ATM " << endl;
        cout << "1. Balance Inquiry" << endl;
        cout << "2. Withdrawal" << endl;
        cout << "3. Deposit" << endl;
        cout << "4. Change PIN" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                account.displayBalance();
                break;
            case 2:
                account.withdraw();
                break;
            case 3:
                account.deposit();
                break;
            case 4: {  
                string oldPin, newPin;
                cout << "Enter old PIN: ";
                cin >> oldPin;

                if (account.authenticate(oldPin)) {
                    cout << "Enter new PIN: ";
                    cin >> newPin;
                    account.setPin(newPin);
                    cout << "PIN changed successfully!" << endl;
                } else {
                    cout << "Invalid old PIN. PIN not changed." << endl;
                }
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid option. Try again!" << endl;
        }
    } while (choice != 5);

    return 0;
}
