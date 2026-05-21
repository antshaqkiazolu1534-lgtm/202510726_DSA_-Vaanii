#include <iostream>
#include <string>
using namespace std;

const string PIN = "1234"; // default PIN
int balance = 0;
string transactions[100];
int transactionCount = 0;

bool authenticate() {
    string enteredPin;
    int attempts = 0;
    while (attempts < 3) {
        cout << "Enter PIN: ";
        cin >> enteredPin;
        if (enteredPin == PIN) return true;
        else {
            cout << "Incorrect PIN. Try again.\n";
            attempts++;
        }
    }
    return false;
}

void recordTransaction(string type, int amount) {
    transactions[transactionCount++] = type + " " + to_string(amount);
}

void checkBalance() {
    cout << "Current Balance: " << balance << endl;
}

void depositMoney() {
    int amount;
    cout << "Enter deposit amount: ";
    cin >> amount;
    balance += amount;
    recordTransaction("Deposit", amount);
    cout << "Deposit successful.\n";
}

void withdrawMoney() {
    int amount;
    cout << "Enter withdrawal amount: ";
    cin >> amount;
    if (amount <= balance) {
        balance -= amount;
        recordTransaction("Withdraw", amount);
        cout << "Withdrawal successful.\n";
    } else {
        cout << "Insufficient balance.\n";
    }
}

void viewTransactions() {
    cout << "Transaction History:\n";
    for (int i = 0; i < transactionCount; i++) {
        cout << i + 1 << ". " << transactions[i] << endl;
    }
}

void menu() {
    int choice;
    do {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Transactions\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: checkBalance(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: viewTransactions(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

int main() {
    if (authenticate()) {
        cout << "Login successful!\n";
        menu();
    } else {
        cout << "Too many failed attempts. Exiting...\n";
    }
    return 0;
}
