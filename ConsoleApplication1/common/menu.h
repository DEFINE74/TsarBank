#ifndef H_MENU
#define H_MENU

#include "user.h"

void WelcomeMenu(BankUser& user, int& now_index);
void InterfaceHandler(BankUser& user, int& now_index);
bool IsUserRegistered(const BankUser& user);
//check_balance.cpp
void CheckBalance(BankUser& user, int& nowIndex);
double GetBalance(const BankUser& user);
#endif 