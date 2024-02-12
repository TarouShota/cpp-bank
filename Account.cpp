//
// Created by taroushota on 19/11/23.
//
#include "Account.h"
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

Account::Account(int id, int balance, char *customerName) {
    m_accID = id;
    m_balance = balance;
    m_customerName = new char[strlen(customerName) + 1];
    strcpy(m_customerName, customerName);

}

Account::Account(Account &copyAccount) {
    m_accID = copyAccount.GetAccountID();
    m_balance = copyAccount.GetBalance();
    m_customerName = new char[strlen(copyAccount.GetCustomerName())];
    strcpy(m_customerName, copyAccount.GetCustomerName());

}
