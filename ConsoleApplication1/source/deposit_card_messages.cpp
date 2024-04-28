#include <iostream>

#include "other.h"

using std::cout, std::endl, std::string;


void CardNumberError() {
    cout << endl << "Неверный номер карты. Возврат к вводу номера..." << endl;
    PauseAndClear();
}
void MoneyAmountError() {
    cout << endl << "Недопустимое сумма." << endl << "Возврат к вводу..." << endl << endl;
    PauseAndClear();
}

void EnterSummMessage() {
    cout << endl << "Введите желаемую сумму (Лимит: 100 000 рублей): ";
}
void PayWithComissionMessage(double comission, double money_summ) {
    cout << "С учётом комиссии в виде " << comission * 100 <<
        "%. Вам нужно будет заплатить: " << money_summ + (money_summ * comission) << " рублей" << endl << endl;

}
void WannaDepositMessage(double comission, int& now_index, double money_summ) {
    ClearConsole(); TsarBankMessage();
    cout << "Вы ввели сумму в размере: " << money_summ << " рублей." << endl;
    PayWithComissionMessage(comission, money_summ);
    cout << (now_index == 1 ? "> " : "  ") << "1) Перевести" << endl;
    cout << (now_index == 2 ? "> " : "  ") << "2) Ввести сумму заново" << endl;
    cout << (now_index == 3 ? "> " : "  ") << "3) Главное меню" << endl;
}
void DepositCardMessage() {
    ClearConsole(); TsarBankMessage();
    cout << "Пополнение картой." << endl;
    cout << endl << "Введите номер карты (допустимое количество символов - 16, ввод - 4 цифры, затем пробел): ";
}
void SuccessfullDepositMessage(BankUser& user) {
    cout << endl << "Успешно. На вашем счёте: " << user.balance << " рублей" << endl;
}

void ShowComissionMessage(const double comission, const std::string bank_system) {
    cout << "Платежная система вашей карты - '" << bank_system << "'." << " Ваша комиссия составляет: " << comission * 100 << "%." << endl;
}

