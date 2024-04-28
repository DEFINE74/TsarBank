#ifndef H_DEPOSIT_CARD_MESSAGES
#define H_DEPOSIT_CARD_MESSAGES


void CardNumberError();
void EnterSummMessage();
void MoneyAmountError();
void WannaDepositMessage(double comission, int& now_index, double money_summ);
void SuccessfullDepositMessage(BankUser& user);
void PayWithComissionMessage(double comission, double money_summ);
void DepositCardMessage();

void ShowComissionMessage(const double comission, const std::string bank_system);

#endif
