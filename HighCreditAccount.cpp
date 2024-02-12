//
// Created by taroushota on 19/11/23.
//
#include "HighCreditAccount.h"
#include "SavingAccount.h"
#include "map"
#include "iostream"
//  "Credit Rating(A:1, B:2, C:3):";

HighCreditAccount::HighCreditAccount(int id, int balance, char *customerName, int rate, int specialRate)
                                : SavingAccount(id, balance, customerName, rate) {

    m_SpecialRate = specialInterestMap.at(specialRate);

}

void HighCreditAccount::Deposit(int money) {
    //Base + Special
    int withAddedSpecial = money + (money*m_SpecialRate/100);
    //Base + Special + Normal Rate
    SavingAccount::Deposit(withAddedSpecial);
}
