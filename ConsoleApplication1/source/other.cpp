#include <iostream>
#include "user.h"
#include "menu.h"
using std::cout, std::endl;
void PauseAndClear() {
    system("pause");
    system("cls");
}
void ClearConsole() {
    system("cls");
}
void ErrorMessage() {
    cout << endl << "������������ ��������! ����������� � ������..." << endl;
    PauseAndClear();
}
void BackToMenuMessage(BankUser& user, int& now_index) {
    cout << endl << "����������� � �������� ����..." << endl << endl;
    PauseAndClear();
    WelcomeMenu(user, now_index); 
}
void ThanksMessage() {
    cout << endl << "������� �� ������������� ������ �����!";
}
void TsarBankMessage() {
    cout << "����-���� (�)" << endl << endl;
}
/*void GoToMenu() {
    cout << "\n����������� � �������� ����...\n\n";
    PauseAndClear();
    WelcomeMenu(BankUser & user, bool isRunning, int& now_index)
}*/