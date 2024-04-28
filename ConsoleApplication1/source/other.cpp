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
    cout << endl << "Неправильная операция! Возвращение к выбору..." << endl;
    PauseAndClear();
}
void BackToMenuMessage(BankUser& user, int& now_index) {
    cout << endl << "Возвращение к главному меню..." << endl << endl;
    PauseAndClear();
    WelcomeMenu(user, now_index); 
}
void ThanksMessage() {
    cout << endl << "Спасибо за использование нашего банка!";
}
void TsarBankMessage() {
    cout << "Царь-банк (С)" << endl << endl;
}
/*void GoToMenu() {
    cout << "\nВозвращение к главному меню...\n\n";
    PauseAndClear();
    WelcomeMenu(BankUser & user, bool isRunning, int& now_index)
}*/