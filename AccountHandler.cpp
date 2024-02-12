//
// Created by taroushota on 25/09/23.
//

#include "AccountHandler.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "SavingAccount.h"
#include "HighCreditAccount.h"

using namespace std;



const int NAME_LEN_2 = 40;

Account *allAccounts[MAX_ACC_NUM_2];

//int accNum = 0;      // # of accounts
void AccountHandler::ShowMenu() {
    cout << "-----Menu------" << endl;
    cout << "1. Make an Account" << endl;
    cout << "2. Delete an Account" << endl;
    cout << "3. Delete all Accounts" << endl;
    cout << "4. Deposit" << endl;
    cout << "5. Withdrawal" << endl;
    cout << "6. Display all" << endl;
    cout << "7. Exit program" << endl;
}

void AccountHandler::updateTotalAccountNumber(int updateBy) {
    accNum = accNum + updateBy;
}

void AccountHandler::gatherCommonAccountInfo(int &id, char *name, int &balance, int &interestRate) {
    cout << "[Make Account]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cin.ignore();
    cout << "Customer Name: ";
    cin.getline(name, NAME_LEN_2);
    cout << "Deposit amount: ";
    cin >> balance;
    cout << endl;
    cout << "Interest Rate: ";
    cin >> interestRate;
    cout << endl;
}

void AccountHandler::makeSavingAccount() {
    int id;
    char name[NAME_LEN_2];
    int balance;
    int interestRate;

    if (accNum >= MAX_ACC_NUM_2) {
        cout << "Sorry! cannot make an account anymore." << endl;
        return;
    }

    gatherCommonAccountInfo(id, name, balance, interestRate);

    if (AccountHandler::getAccIdx(id) != -1) {
        cout << "Error: Existing account ID" << endl;
        return;
    }

    auto *newAccount = new SavingAccount{id, balance, name, interestRate};
    allAccounts[accNum] = newAccount;
    cout << allAccounts[accNum]->GetAccountID() << endl;
    updateTotalAccountNumber(+1);

void AccountHandler::makeHighCreditAccount() {
    int id;
    char name[NAME_LEN_2];
    int balance;
    int interestRate;
    int specialRate;

    if (accNum >= MAX_ACC_NUM_2) {
        cout << "Sorry! cannot make an account anymore." << endl;
        return;
    }

    gatherCommonAccountInfo(id, name, balance, interestRate);
    cout << "Credit Rating(A:1, B:2, C:3):";
    cin >> specialRate;
    cout << endl;


    if (AccountHandler::getAccIdx(id) != -1) {
        cout << "Error: Existing account ID" << endl;
        return;
    }
    auto *newAccount = new HighCreditAccount{id, balance, name, interestRate, specialRate};
    allAccounts[accNum] = newAccount;
    cout << allAccounts[accNum]->GetAccountID() << endl;
    updateTotalAccountNumber(+1);
}

void AccountHandler::makeAccount() {
    int accountChoice;
    cout << "[Select Account Type] \n" <<
         "1. Saving Account \n" <<
         "2. High Credit Account" << endl;
    cin >> accountChoice;
    cin.ignore();
    switch (accountChoice) {
        case 1:
            AccountHandler::makeSavingAccount();
            break;
        case 2:
            AccountHandler::makeHighCreditAccount();
            break;
        default:
            break;

    }


}

void AccountHandler::deleteAccount() {
    int id;
    cout << "Specify the Account ID to delete:" << endl;
    cin >> id;

    for (int i = 0; i < accNum; i++) {
        if (allAccounts[i]->GetAccountID() == id) {
            delete allAccounts[i];
            for (int j = i; j < accNum - 1; j++) {
                allAccounts[j] = allAccounts[j + 1];
            }

            allAccounts[accNum - 1] = nullptr;
            updateTotalAccountNumber(-1);
            cout << "Account was successfully deleted" << endl;
            return;
        }
    }

    cout << "Account with an id:" << id << " was not found" << endl;
}

void AccountHandler::deleteAllAccounts() {
    accNum = 0;
    cout << "All existing accounts have been deleted" << endl;
}


void AccountHandler::depositMoney() {


    int money;
    int id;
    cout << "[Deposit]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Deposit amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (allAccounts[i]->GetAccountID() == id) {
            allAccounts[i]->Deposit(money);

            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void AccountHandler::withdrawMoney() {
    int money;
    int id;
    cout << "[Withdrawal]" << endl;
    cout << "Account ID: ";
    cin >> id;
    cout << "Withdrawal amount: ";
    cin >> money;

    for (int i = 0; i < accNum; i++) {
        if (allAccounts[i]->GetAccountID() == id) {
            if (allAccounts[i]->GetBalance() < money) {
                cout << "Not enough balance" << endl << endl;
                return;
            }

            allAccounts[i]->Withdraw(money);
            cout << "Withdrawal completed" << endl << endl;
            return;
        }
    }
    cout << "This ID is not valid." << endl << endl;
}

void AccountHandler::showAllAccInfo() {
    for (int i = 0; i < accNum; i++) {
        cout << "Account ID: " << allAccounts[i]->GetAccountID() << endl;
        cout << "Name: " << allAccounts[i]->GetCustomerName() << endl;
        cout << "Balance: " << allAccounts[i]->GetBalance() << endl << endl;
    }
}

int AccountHandler::getAccIdx(int id) {
    for (int i = 0; i < accNum; i++) {
        if (allAccounts[i]->GetAccountID() == id) {
            return i;
        }
    }
    return -1;
}





