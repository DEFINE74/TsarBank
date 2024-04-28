#include <iostream>
#include <string>

#include "other.h"
#include "user.h"

using std::string, std::cout, std::endl;

void DepositPhoneMessage() {
    ClearConsole(); TsarBankMessage();
    cout << "Пополнение по телефону." << endl;
    cout << endl << "Введите номер телефона (Доступные страны: Россия, Беларусь, Иран, Китай): ";
}

void PhoneNumberError() {
    cout << endl << "Неверный номер телефона. Возврат к вводу..." << endl;
    PauseAndClear();
}
void ShowCountryMessage(const double comission, const std::string country) {
    cout << endl << "Страна номера телефона - '" << country << "'." << " Ваша комиссия составляет: " << comission * 100 << "%." << endl;
}