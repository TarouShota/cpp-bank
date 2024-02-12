//
// Created by taroushota on 19/11/23.
//

#ifndef OOP_HW_8_EDITED_HIGHCREDITACCOUNT_H
#define OOP_HW_8_EDITED_HIGHCREDITACCOUNT_H
#include "SavingAccount.h"
#include "map"

class HighCreditAccount : public SavingAccount {
private:
    int m_SpecialRate;
    std::map<int,int> specialInterestMap{{1, 7}, {2, 4}, {3, 2}};
public:

    HighCreditAccount(int id, int balance, char *customerName, int rate,int special);
    virtual void Deposit(int money);
};

#endif //OOP_HW_8_EDITED_HIGHCREDITACCOUNT_H
