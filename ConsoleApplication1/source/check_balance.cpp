#include <iostream>

#include "user.h"
#include "other.h"

double GetBalance(const BankUser& user) {
    return user.balance;
}
void CheckBalance(BankUser& user, int& nowIndex) {
    using std::cout, std::endl;
    ClearConsole(); TsarBankMessage();

    cout << "�������, " << user.GetLogin();
    cout << "\n��� ������� ������: " << GetBalance(user) << " ������" << endl;
    BackToMenuMessage(user, nowIndex);
}