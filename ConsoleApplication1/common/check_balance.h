#ifndef H_CHECK_BALANCE
#define H_CHECK_BALANCE

#include "user.h"
double GetBalance(const BankUser& user);
void CheckBalance(BankUser& user, int& nowIndex);

#endif
