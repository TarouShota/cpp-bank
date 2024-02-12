cmake_minimum_required(VERSION 3.26)
project(oop_hw_8_edited)

set(CMAKE_CXX_STANDARD 17)

add_executable(oop_hw_8_edited BankMain.cpp
        AccountHandler.cpp
        SavingAccount.h
        HighCreditAccount.h
        Account.h
        BankCommon.h
        Account.cpp
        AccountHandler.h
        HighCreditAccount.cpp
        SavingAccount.cpp)
