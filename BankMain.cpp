#include <iostream>
#include "AccountHandler.h"
#include "BankCommon.h"



using namespace std;


int main() {
    int choice;
    AccountHandler manager{};
    while (true) {



        manager.ShowMenu();
        cout << "Select menu: ";
        cin >> choice;
        cout << endl;

        switch (bank(choice)) {
        case bank::MAKE:
            manager.makeAccount();
            break;
        case bank::DELETE:
            manager.deleteAccount();
            break;
        case bank::DELETE_ALL:
            manager.deleteAllAccounts();
            break;
        case bank::DEPOSIT:
            manager.depositMoney();
            break;
        case bank::WITHDRAW:
            manager.withdrawMoney();
            break;
        case bank::INQUIRE:
            manager.showAllAccInfo();
            break;
        case bank::EXIT:
            return 0;
        default:
            cout << "Illegal selection.." << endl;
        }
    }
    return 0;

}