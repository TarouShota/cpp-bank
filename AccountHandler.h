//
// Created by taroushota on 19/11/23.
//

#ifndef OOP_HW_8_EDITED_ACCOUNTHANDLER_H
#define OOP_HW_8_EDITED_ACCOUNTHANDLER_H

#endif //OOP_HW_8_EDITED_ACCOUNTHANDLER_H
#ifndef _BANK_H_
#define _BANK_H_
#include "Account.h"
const int NAME_LEN = 40;
const int MAX_ACC_NUM_2 = 100;



class AccountHandler{
private:
    Account* allAccounts[MAX_ACC_NUM_2]{};
    int accNum ;      // # of accounts
public:
    AccountHandler(){
        accNum = 0;
    }
    void ShowMenu();
    void updateTotalAccountNumber(int);
    void makeAccount();
    void makeSavingAccount();
    void makeHighCreditAccount();
    void deleteAccount();
    void deleteAllAccounts();
    void depositMoney();
    void withdrawMoney();
    void showAllAccInfo();

    static void gatherCommonAccountInfo(int& id, char* name, int& balance,int& interestRate);
    int getAccIdx(int);
};

#endif // _BANK_H_