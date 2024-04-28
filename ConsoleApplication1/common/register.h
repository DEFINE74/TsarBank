#ifndef H_REGISTER

#define H_REGISTER

#include "user.h"


void WannaRegister(BankUser& user, bool is_running, int& now_index);
int RegisterHandler(BankUser& user, int& now_index);
void RegistrationProcess(BankUser& user, int& nowIndex);


#endif

