#include <iostream>

#include "user.h"
#include "register.h"
#include "other.h"
#include "menu_messages.h"
#include "key.h"
#include "check_balance.h"
#include "deposit_redirector.h"

inline bool IsUserRegistered(const BankUser& user) { return user.is_registered == 1; }

void InterfaceHandler(BankUser& user, int& now_index) {
    bool is_running = true;
    switch (now_index) {
    case 1:
        CheckBalance(user, now_index);
    case 2:
        now_index = 1;
        DepositMethod(user, is_running, now_index);
    default:
        break;
    }
}
void WelcomeMenu(BankUser& user, int& now_index) {
    now_index = 1;

    bool is_running = true;

    TsarBankMessage();
    if (!(IsUserRegistered(user))) {
        
        WannaRegister(user, is_running, now_index);
    }
    else {
        int maxIndex = 5;
        while (is_running) {
            InterfaceMessage(user,now_index);
            KeyWait(maxIndex, now_index, is_running);
        }
        InterfaceHandler(user, now_index);
        /*cin >> userChoise;
        switch (userChoise) {
        case 1:
            CheckBalance(user);
            break;
        case 2:
            PopUpBalance(user);
            break;
        case 3:
            WithDrawals(user);
        }*/
    }
}
