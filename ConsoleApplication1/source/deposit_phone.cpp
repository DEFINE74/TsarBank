#include <iostream>

#include "user.h"
#include "other.h"
#include "deposit_card.h"
#include "deposit_phone.h"
#include "deposit_card_messages.h"
#include "deposit_phone_messages.h"
#include "key.h"


using std::string, std::cin;

void InputPhoneNumber(BankUser& user) {
	string phone_num;
	DepositPhoneMessage();

	getline(cin, phone_num);
	phone_num = StringTransformation(phone_num);

	CheckPhoneNumbersLength(user, phone_num);
}
void CheckPhoneNumbersLength(BankUser& user, string phone_num) {
	if (phone_num.size() > 12 || phone_num.size() <= 0) { PhoneNumberError(); InputPhoneNumber(user); }
	else { PhoneNumberHandler(user, phone_num); }
}

void PhoneCountryIdentify(const double comission, const std::string country) {
    ShowCountryMessage(comission, country);
}

void PhoneNumberHandler(BankUser& user, string phone_num) {
	const string COUNTRY_RUSSIA = "Россия", COUNTRY_BELARUS = "Беларусь", COUNTRY_IRAN = "Иран", COUNTRY_CHINA = "Китай";
	const double COMISSION_RUSSIA = 0, COMISSION_BELARUS = 0.015, COMISSION_IRAN = 0.05, COMISSION_CHINA = 0.1;
	
    const string first_symbols = phone_num.substr(0,1);
    const string first_two_symbols = phone_num.substr(0, 2);
    const string first_three_symbols = phone_num.substr(0, 3);
    
    
    if (first_symbols == "7" || first_two_symbols == "89" || first_two_symbols == "88") {
        PhoneCountryIdentify(COMISSION_RUSSIA, COUNTRY_RUSSIA);
        PhoneInputMoneyWithCommision(user, COMISSION_RUSSIA);
    }
    else if (first_two_symbols == "98") {
        PhoneCountryIdentify(COMISSION_IRAN, COUNTRY_IRAN);
        PhoneInputMoneyWithCommision(user, COMISSION_IRAN);
    }
    else if (first_two_symbols == "86") {
        PhoneCountryIdentify(COMISSION_CHINA, COUNTRY_CHINA);
        PhoneInputMoneyWithCommision(user, COMISSION_CHINA);
    }
    else if (first_three_symbols == "375") {
        PhoneCountryIdentify(COMISSION_BELARUS, COUNTRY_BELARUS);
        PhoneInputMoneyWithCommision(user, COMISSION_BELARUS);
    }
    else {
        PhoneNumberError(); InputPhoneNumber(user);
    }
}

void PhoneInputMoneyWithCommision(BankUser& user, double comission) {
    EnterSummMessage();
    double money_summ = PhoneGetFinalMoneyValue(user,comission);
    PhoneWillYouPay(user, money_summ, comission);      
}
double PhoneGetFinalMoneyValue(BankUser& user, double comission) {
    double money_summ = EnterMoneyAmount();
    if (CheckMoneyLimit(money_summ)) { return money_summ; }
    else {
        MoneyAmountError();
        TsarBankMessage();
        PhoneInputMoneyWithCommision(user, comission);
        return 0;
    }
}
void PhoneWillYouPay(BankUser& user, double money_summ, double comission) {
    bool is_running = true;
    int now_index = 1, max_index = 3;
    while (is_running) {
        WannaDepositMessage(comission, now_index, money_summ);
        KeyWait(max_index, now_index, is_running);
    }
    PhoneWillYouPayHandler(user, now_index, money_summ, comission);
}
double PhoneWillYouPayHandler(BankUser& user, int& now_index, double money_summ, double comission) {
    switch (now_index) {
    case 1:
        user.balance = money_summ;
        SuccessfullDepositMessage(user);
        BackToMenuMessage(user, now_index);
        break;
    case 2:
        PhoneInputMoneyWithCommision(user, comission);
        break;
    case 3:
        BackToMenuMessage(user, now_index);
        break;
    default:
        ErrorMessage();
        PhoneWillYouPay(user, money_summ, comission);
        break;
    }
    return 0;
}
/*
void PopUpPhone(BankUser& user) {
    string phoneNumber;
    double commission;
    system("cls");
    cout << "Царь-банк (С)\n";
    cout << "\nВведите номер телефона (Доступные страны: Россия, Беларусь, Иран, Китай): ";
    getline(cin, phoneNumber);
    if (phoneNumber.size() == 11) {
        if (phoneNumber.substr(1) == "7") {
            commission = 0;
            cout << "\nСтрана номера телефона - Россия. Комиссия - " << (commission * 100) << "%.";
        }
        else if (phoneNumber.substr(1, 4) == "375") {
            commission = 0.015;
            cout << "\nСтрана номера телефона - Беларусь. Комиссия - " << (commission * 100) << "%.";
        }
        else if (phoneNumber.substr(1, 2) == "98") {
            commission = 0.05;
            cout << "\nСтрана номера телефона - Иран. Комиссия - " << (commission * 100) << "%.";
        }
        else if (phoneNumber.substr(1, 2) == "86") {
            commission = 0.1;
            cout << "\nСтрана номера телефона - Китай. Комиссия - " << (commission * 100) << "%.";
        }
    }


}*/