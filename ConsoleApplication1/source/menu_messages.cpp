#include <iostream>

#include "user.h"
#include "other.h"

using std::cout, std::endl;

void InterfaceMessage(BankUser& user,int& now_index) {
    ClearConsole();
    TsarBankMessage();
    cout << "Добрый день, " << user.GetLogin() << endl;
    cout << endl << "Что вы хотите сегодня сделать?" << endl;
    cout << (now_index == 1 ? "> " : "  ") << "1) Текущий баланс" << endl;
    cout << (now_index == 2 ? "> " : "  ") << "2) Пополнить баланс" << endl;
    cout << (now_index == 3 ? "> " : "  ") << "3) Вывести средства" << endl;
    cout << (now_index == 4 ? "> " : "  ") << "4) Сделать вклад" << endl;
    cout << (now_index == 5 ? "> " : "  ") << "5) Пополнить баланс" << endl;
}
