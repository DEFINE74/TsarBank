#include <iostream>

#include "user.h"
#include "other.h"

double GetBalance(const BankUser& user) {
    return user.balance;
}
void CheckBalance(BankUser& user, int& nowIndex) {
    using std::cout, std::endl;
    ClearConsole(); TsarBankMessage();

    cout << "Дорогой, " << user.GetLogin();
    cout << "\nВаш текущий баланс: " << GetBalance(user) << " рублей" << endl;
    BackToMenuMessage(user, nowIndex);
}