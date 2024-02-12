//
// Created by taroushota on 19/11/23.
//

#ifndef OOP_HW_8_EDITED_ACCOUNT_H
#define OOP_HW_8_EDITED_ACCOUNT_H

class Account {
private:
    int m_accID;
    int m_balance;
    char* m_customerName;
public:
    Account(int id, int balance, char* customerName);
    Account(Account &copyAccount);


    ~Account() {
        delete[] m_customerName;
    }
    int GetAccountID() const{
        return m_accID;
    }
    int GetBalance() const {
        return m_balance;
    }
    char* GetCustomerName()const {
        return m_customerName;
    }
    virtual void Deposit(int amount) {
        m_balance = m_balance + amount;
    }

    int Withdraw(int amount) {
        m_balance = m_balance - amount;
        return m_balance;
    }
};

#endif //OOP_HW_8_EDITED_ACCOUNT_H
