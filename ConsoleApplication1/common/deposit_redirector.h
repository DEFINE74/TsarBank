#ifndef H_DEPOSIT_REDIRECTOR
#define H_DEPOSIT_REDIRECTOR

#include "user.h"

int DepositHandler(BankUser& user, int& now_index);
void DepositMethod(BankUser& user, bool is_running, int& now_index);

#endif 

