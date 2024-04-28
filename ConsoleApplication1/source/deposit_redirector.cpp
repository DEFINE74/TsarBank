#include <iostream>

#include "other.h"
#include "deposit_redirector_messages.h"
#include "user.h"
#include "key.h"
#include "deposit_card.h"
#include "deposit_phone.h"

void DepositMethod(BankUser& user, bool is_running, int& now_index);

int DepositHandler(BankUser& user, int& now_index) {
    bool is_running = true;

    switch (now_index) {
    case 1:
        ClearConsole();
        InputCardNumber(user);
        break;
    case 2:
        ClearConsole();
        InputPhoneNumber(user);
        break;
    case 3:
        BackToMenuMessage(user, now_index);
        return 3;
    default:
        ErrorMessage();
        DepositMethod(user, is_running, now_index);
        break;
    }
    return 0;
}
void DepositMethod(BankUser& user, bool is_running, int& now_index) {
    int maxIndex = 3;
    while (is_running) {
        DepositStartMessage(now_index);
        KeyWait(maxIndex, now_index, is_running);
    }
    DepositHandler(user, now_index);
}

/*double PopUpBalance(BankUser& user, bool& isRunning, int& nowIndex) {
    double money, moneyLimit = 100000;
    int userChoise;
    {
        system("cls");
        cout << "����-���� (�)\n";
        cout << "\n�������� ������ ����������.";
        cout << "\n1) ���������� ������ (�������� � ����������� �� �����)";
        cout << "\n2) �� ������ �������� (�������� 25%)";
        cout << "\n3) ����� �� ����������\n";
        cout << "\n�����: ";
    }
    cin >> userChoise;
    cin.ignore();
    switch (userChoise) {
    case 1:
        PopUpCard(user);
        break;
    case 2:
        PopUpPhone(user);
        break;
    case 3:
        PauseAndClear();
        WelcomeMenu(user,);
        break;
    default:
        cout << "\n������������ ��������. ��������� �����.\n";
        PauseAndClear();
        PopUpBalance(user);
        break;
    }
    return user.balance;
}
*/