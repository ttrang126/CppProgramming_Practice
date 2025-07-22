
# CppProgramming_Practice

## Excerise 1: Bank Mangement System
A bank management system in C++ is a beginner's project that is great for students. It is made such that it helps users manage their bank accounts. It allows users to create an account, deposit and withdraw money, and check their account details. This project suits students who want to learn basic programming concepts and Object-Oriented Programming (OOPs) in C++ and test their knowledge. It’s a great learning example for handling user input, managing account transactions, and using C++ classes and objects. 

### Feature

1. Account Creation – Users can open a new bank account by providing their name, account number, and an initial deposit.

2. Deposit Money – Users can add money to their account.

3. Withdraw Money – Users can withdraw money if they have enough balance.

4. Check Account Details – Users can view their account number, holder name, and balance.

### Algorithm
 
**Step 1: Start**

**Step 2: Display Menu Options**

Show the user options:

1. Create Account

2. Deposit Money

3. Withdraw Money

4. Display Account Details

5. Exit

**Step 3: Take User Input for Choice**

1. Read the user's choice.

**Step 4: Perform Actions Based on Choice**

Case 1: Create Account

1. Ask the user for Name, Account Number, and Initial Balance.

2. Create a new BankAccount object and store it in a list.

3. Confirm account creation.

Case 2: Deposit Money

1. Ask the user for Account Number and Deposit Amount.

2. Search for the account in the list.

3. If found, add the amount to the balance and confirm the deposit.

4. If not found, display an error message.

Case 3: Withdraw Money

1. Ask the user for the Account Number and Withdrawal Amount.

2. Search for the account in the list.

3. If found, check if the balance is sufficient.

   - If yes, deduct the amount and confirm the withdrawal.

   - If no, display an insufficient balance message.

4. If the account is not found, display an error message.

Case 4: Display Account Details

1. Ask the user for the Account Number.

2. Search for the account in the list.

3. If found, display the account holder's name, account number, and balance.

4. If not found, display an error message.

Case 5: Exit Program

1. Display a thank-you message.

2. Terminate the program.

**Step 5: Repeat Until User Chooses to Exit**

**Step 6: End**