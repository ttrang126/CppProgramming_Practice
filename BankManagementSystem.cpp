#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

string formatwithCommas(double value)
{
    long long intPart = static_cast<long long>(value);
    double fracPart = value - intPart;

    string numStr = to_string(intPart);
    int insertPos = numStr.length() - 3;
    while (insertPos > 0)
    {
        numStr.insert(insertPos, ",");
        insertPos -= 3;
    }

    if (fracPart > 0)
    {
        int frac = static_cast<int>(fracPart * 100 + 0.5);
        numStr += "." + ((frac < 10 ? "0" : "") + to_string(frac));
    }

    return numStr;
} 

class BankAccount 
{
    private:
        string accountName;
        string accountNumber;
        double balance;
    public:
        BankAccount()
        {
            accountName = "";
            accountNumber = "";
            balance = 0.0;
        }

        string getAccountName() const { return accountName; }
        void setAccountName(const string&name) { accountName = name; }

        string getAccountNumber() const { return accountNumber; }
        void setAccountNumber(const string& number) { accountNumber = number; }

        double getBalance() const { return balance; }
        void setBalance(double newBalance) { balance = newBalance; }

        ~BankAccount() {}

        void deposit(double amount)
        {
            if (amount > 0) 
            {
                balance += amount;
                cout << "Deposited: " << fixed << setprecision(0) << formatwithCommas(amount) << " VND successfully to account: " << accountName << endl;
            }
            else
            {
                cout << "Invalid deposit amount!" << endl;
            }
        }

        void withdraw(double amount)
        {
            if(amount > 0 && amount <= balance)
            {
                balance -= amount;
                cout << "Withdrawn: " << fixed << setprecision(0) << formatwithCommas(amount) << " VND successfully from account: " << accountName << endl;
            }
            else if(amount > balance)
            {
                cout << "Insufficient balance!" << endl;
            }
            else
            {
                cout << "Invalid withdrawal amount!" << endl;
            }
        }

        void display()
        {
            cout << "Account Name: " << accountName << endl;
            cout << "Account Number: " << accountNumber << endl;
            cout << "Balance: " << fixed << setprecision(0) << formatwithCommas(balance) << " VND" << endl;
        }
};

BankAccount* findAccount(vector<BankAccount>& accounts, const string& number)
{
    for(auto& account : accounts)
    {
        if(account.getAccountNumber() == number) return &account;
    }
    return nullptr;
}

int main()
{
    vector<BankAccount> accounts;
    int choice;

    while(1)
    {
        cout << "=========Bank Management System=========" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Display Account Information" << endl;
        cout << "5. Exit" << endl;   
        
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            BankAccount newAcc;
            string name, number;
            double initialBalance;

            cout << "Enter Account Name: ";
            getline(cin, name);
            newAcc.setAccountName(name);

            cout << "Enter Account Number: ";
            getline(cin, number);
            newAcc.setAccountNumber(number);
            
            cout << "Enter Initial Balance: ";
            cin >> initialBalance;
            newAcc.setBalance(initialBalance);
            
            accounts.push_back(newAcc);
            cout << "Account created successfully!" << endl;
        } 
        
        else if (choice == 2)
        {
            string number;
            double amount;
            cout << "Enter Account Number: ";
            getline(cin, number);

            BankAccount* account = findAccount(accounts, number);
            if (account)
            {
                cout << "Enter the Amount to Deposit: " << endl;
                cin >> amount;
                account->deposit(amount);
            }
            else
            {
                cout << "Invalid Account!" << endl;
            }
        }

        else if(choice == 3)
        {
            string number;
            double amount;

            cout << "Enter Account Number: ";
            getline(cin, number);

            BankAccount* account = findAccount(accounts, number);
            if(account)
            {
                cout << "Enter the Withdrawal amount: " << endl;
                cin >> amount;
                account->withdraw(amount);
            }
            else
            {
                cout << "Invalid Account!" << endl;
            }
        }

        else if (choice == 4)
        {
            string number;

            cout << "Enter Account Number: ";
            getline(cin, number);
            
            BankAccount* account = findAccount(accounts, number);
            if(account)
            {
                account->display();
            }
            else
            {
                cout << "Invalid Account!" << endl;
            }
        }

        else if(choice == 5)
        {
            cout << "Thank you!" << endl;
            break;
        }
    }

    return 0;
}