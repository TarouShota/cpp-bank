//
// Created by taroushota on 19/11/23.
//

#ifndef OOP_HW_8_EDITED_SAVINGACCOUNT_H
#define OOP_HW_8_EDITED_SAVINGACCOUNT_H
#include "Account.h"
class SavingAccount: public Account{
private:
    int m_interestRate{};
public:
    SavingAccount(int id, int balance, char *customerName, int rate);
    virtual void Deposit(int money);
};


#endif //OOP_HW_8_EDITED_SAVINGACCOUNT_H
