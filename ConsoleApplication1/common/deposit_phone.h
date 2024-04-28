#ifndef H_DEPOSIT_PHONE
#define H_DEPOSIT_PHONE

#include "other.h"

using std::string;

void InputPhoneNumber(BankUser& user);
void CheckPhoneNumbersLength(BankUser& user, string phone_num);
void PhoneCountryIdentify(const double comission, const std::string country);
void PhoneNumberHandler(BankUser& user, string phone_num);
void PhoneInputMoneyWithCommision(BankUser& user, double comission);
void PhoneWillYouPay(BankUser& user, double money_summ, double comission);
double PhoneWillYouPayHandler(BankUser& user, int& now_index, double money_summ, double comission);

void PhoneInputMoneyWithCommision(BankUser& user, double comission);
double PhoneGetFinalMoneyValue(BankUser& user, double comission);
#endif 