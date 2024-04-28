#include <iostream>

#include "other.h"

using std::cout, std::endl;

void DepositStartMessage(int& now_index) {
    ClearConsole(); TsarBankMessage();
    cout << "Выберите способ пополнения." << endl << endl;
    cout << (now_index == 1 ? "> " : "  ") << "1) Банковской картой (комиссия в зависимости от банка)" << endl;
    cout << (now_index == 2 ? "> " : "  ") << "2) По номеру телефона (комиссия в зависимости от страны)" << endl;
    cout << (now_index == 3 ? "> " : "  ") << "3) Выход из пополнения" << endl;
}