#include <iostream>

#include "user.h"
#include "other.h"

using std::cout, std::endl;

void RegisterMessage(int& now_index) {
    ClearConsole();
    cout << "Царь-банк (С)" << endl;
    cout << endl << "Добро пожаловать, вы не зарегистрированы." << endl;
    cout << "Хотите зарегистрироваться ? " << endl << endl;
    cout << (now_index == 1 ? "> " : "  ") << "1) Да\n";
    cout << (now_index == 2 ? "> " : "  ") << "2) Нет\n";
}
void LoginAndPasswordMessage() {
    cout << "Царь-банк (С)" << endl;
    cout << endl << "Для регистрации вам потребуется создать свой логин и пароль. Мы предлагаем подобрать вам логин" << endl;
    cout << endl << "Не больше 10 символов!" << endl;
    cout << "Логин: ";
}
void RegisteredLikeMessage(BankUser& user) {
    cout << endl << "Вы зарегистрировались в системе как " << user.GetLogin();
}