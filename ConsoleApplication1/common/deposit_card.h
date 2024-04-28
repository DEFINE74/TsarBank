#ifndef H_DEPOSIT_CARD
#define H_DEPOSIT_CARD

#include "user.h"

using std::string;

void InputCardNumber(BankUser& user);
string StringTransformation(string& card_num);

void CheckNumbersLength(BankUser& user, string card_num);

void CardNumberHandler(BankUser& user, string card_num);
void BankSystemIdentify(const double comission, const std::string bank_system);

void CardInputMoneyWithCommision(BankUser& user, double comission);
double CardGetFinalMoneyValue(BankUser& user, double comission);
double EnterMoneyAmount();
bool CheckMoneyLimit(double money_summ);

void CardWillYouPay(BankUser& user, double money, double comission);
double CardWillYouPayHandler(BankUser& user, int& now_index, double money_summ, double comission);

#endif 

