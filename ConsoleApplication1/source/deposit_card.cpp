#include <iostream>
#include <string>

#include "user.h"
#include "key.h"
#include "other.h"
#include "deposit_phone.h"
#include "deposit_card_messages.h"
#include "deposit_card.h"

#define DEPOSIT_CARD

using std::string, std::cin;

// function - 1
void InputCardNumber(BankUser& user) {
	string card_num;
	DepositCardMessage();

	getline(cin, card_num);
	card_num = StringTransformation(card_num);
	CheckNumbersLength(user, card_num);
}

//function 2 - converting
string StringTransformation(string& card_num) {
	card_num.erase(remove(card_num.begin(), card_num.end(), ' '), card_num.end());
	return card_num;
}

// function - 3
void CheckNumbersLength(BankUser& user, string card_num) {
	if (card_num.size() != 16 || card_num.size() <= 0) { CardNumberError(); InputCardNumber(user); }
	else { CardNumberHandler(user, card_num); }
}

//function - 4
void CardNumberHandler(BankUser& user, string card_num) {
	const string MIR_BANK = "ÌÈÐ", VISA_BANK = "Visa", MASTERCARD_BANK = "MasterCard";
	const char MIR_SYMBOL = '2', VISA_SYMBOL = '4', MASTERCARD_SYMBOL = '5';
	const double MIR_COMISSION = 0.05, VISA_COMISSION = 0.1, MASTERCARD_COMISSION = 0.2;

	switch (card_num[0]) {
	case MIR_SYMBOL:
		BankSystemIdentify(MIR_COMISSION, MIR_BANK);
		CardInputMoneyWithCommision(user, MIR_COMISSION);
		break;
	case VISA_SYMBOL:
		BankSystemIdentify(VISA_COMISSION, VISA_BANK);
		CardInputMoneyWithCommision(user, VISA_COMISSION);
		break;
	case MASTERCARD_SYMBOL:
		BankSystemIdentify(MASTERCARD_COMISSION, MASTERCARD_BANK);
		CardInputMoneyWithCommision(user, MASTERCARD_COMISSION);
		break;
	default:
		CardNumberError(); InputCardNumber(user);
		break;
	}
}

//from function 4
//function 4.1
void BankSystemIdentify(const double comission, const std::string bank_system) {
	ShowComissionMessage(comission, bank_system);
}

//function 5
void CardInputMoneyWithCommision(BankUser& user, double comission) {
	EnterSummMessage();
	double money_summ = CardGetFinalMoneyValue(user, comission);
	CardWillYouPay(user, money_summ, comission);
}

//from function 5
//function 5.1
double CardGetFinalMoneyValue(BankUser& user, double comission) {
	double money_summ = EnterMoneyAmount();
	if (CheckMoneyLimit(money_summ)) { return money_summ; }
	else { 
		MoneyAmountError();  
		CardInputMoneyWithCommision(user,comission);
		return 0; 
	}
}
//function 5.2 - converting
double EnterMoneyAmount() {
	string old_summ; double transformed_summ;

	try {
		getline(cin, old_summ);
		old_summ = StringTransformation(old_summ);
		transformed_summ = stod(old_summ);
	}
	catch (const std::invalid_argument& ex) {
		return 0;
	}

	return transformed_summ;
}
//function 5.3
bool CheckMoneyLimit(double money_summ) {
	const int MAX_MONEY_VALUE = 100000;
	const int MIN_MONEY_VALUE = 0;

	if (money_summ > MAX_MONEY_VALUE || money_summ <= MIN_MONEY_VALUE) { return false; }
	else { return true; }
}

//function 6 - user change
void CardWillYouPay(BankUser& user, double money_summ, double comission) {
	bool is_running = true;
	int now_index = 1, max_index = 3;
	while (is_running) {
		WannaDepositMessage(comission, now_index, money_summ);
		KeyWait(max_index, now_index, is_running);
	}
	CardWillYouPayHandler(user, now_index, money_summ, comission);
}

//from function 6

//function 6.1
double CardWillYouPayHandler(BankUser& user, int& now_index, double money_summ, double comission) {
	switch (now_index) {
	case 1:
		user.balance = money_summ;
		SuccessfullDepositMessage(user);
		BackToMenuMessage(user, now_index);
		break;
	case 2:
		CardInputMoneyWithCommision(user, comission);
		break;
	case 3:
		BackToMenuMessage(user, now_index);
		break;
	default:
		ErrorMessage();
		CardWillYouPay(user, money_summ, comission);
		break;
	}
	return 0;
}

