#include <iostream>

#include "user.h"
#include "key.h"
#include "other.h"
#include "register_message.h"

using std::string;

void WannaRegister(BankUser& user, bool is_running, int& now_index);

void RegistrationProcess(BankUser& user, int& nowIndex) {
    using std::cin, std::cout, std::endl;
    string login, password;

    LoginAndPasswordMessage();
    cin >> login;
    cin.ignore();

    if (login.size() > 10) {
        cout << "\nПревышено количество допустимых символов. Возвращение к созданию логина..." << endl;
        PauseAndClear();
        RegistrationProcess(user,nowIndex);
    }
    else {
        user.SetLogin(login);

        cout << "Пароль: ";
        cin.ignore();
        getline(cin, password);
        user.SetPassword(password);
        
        RegisteredLikeMessage(user);
        user.is_registered = true;
        BackToMenuMessage(user, nowIndex);
    }
}
int RegisterHandler(BankUser& user, int& now_index) {
    bool is_running = true;

    switch (now_index) {
    case 1:
        ClearConsole();
        RegistrationProcess(user, now_index);
        break;
    case 2:
        ThanksMessage();
        return 2;
    default:
        ErrorMessage();
        WannaRegister(user, is_running, now_index);
        break;
    }
    return 0;
}

void WannaRegister(BankUser& user, bool is_running, int& now_index) {
    int maxIndex = 2;
    while (is_running) {
        RegisterMessage(now_index);
        KeyWait(maxIndex, now_index, is_running);
    }
    RegisterHandler(user, now_index);
}
