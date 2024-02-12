//
// Created by taroushota on 19/11/23.
//
#include "SavingAccount.h"
#include "Account.h"
#include "iostream"


SavingAccount::SavingAccount(int id, int balance, char *customerName, int rate)
        : Account(id, balance, customerName) {
    m_interestRate = rate;
}

void SavingAccount::Deposit(int money) {
 int withNormalRate = money + (money*m_interestRate/100);

    std::cout <<"Depositing: "<<withNormalRate<<std::endl;
    Account::Deposit(withNormalRate);
}