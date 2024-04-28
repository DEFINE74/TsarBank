#include <iostream> 
#include <string> 
#include <conio.h>

#include "user.h"
#include "menu.h"


#ifdef DEBUG
 #define DEBUG 
//2 - пополнить баланс
void PopUpPhoneFinal(BankUser& user, double commission) {

}
void PopUpPhone(BankUser& user) {
    string phoneNumber;
    double commission;
    system("cls");
    cout << "Царь-банк (С)\n";
    cout << "\nВведите номер телефона (Доступные страны: Россия, Беларусь, Иран, Китай): ";
    getline(cin, phoneNumber);
    if (phoneNumber.size() == 11) {
        if (phoneNumber.substr(1) == "7") {
            commission = 0;
            cout << "\nСтрана номера телефона - Россия. Комиссия - " << (commission * 100) << "%.";
        }
        else if (phoneNumber.substr(1,4) == "375") {
            commission = 0.015;
            cout << "\nСтрана номера телефона - Беларусь. Комиссия - " << (commission * 100) << "%.";
        }
        else if (phoneNumber.substr(1, 2) == "98") {
            commission = 0.05;
            cout << "\nСтрана номера телефона - Иран. Комиссия - " << (commission * 100) << "%.";
        }
        else if (phoneNumber.substr(1, 2) == "86") {
            commission = 0.1;
            cout << "\nСтрана номера телефона - Китай. Комиссия - " << (commission * 100) << "%.";
        }
    }

    
}
double PopUpBalance(BankUser& user, bool& isRunning, int& nowIndex) {
    double money, moneyLimit = 100000;
    int userChoise;
    {
        system("cls");
        cout << "Царь-банк (С)\n";
        cout << "\nВыберите способ пополнения.";
        cout << "\n1) Банковской картой (комиссия в зависимости от банка)";
        cout << "\n2) По номеру телефона (комиссия 25%)";
        cout << "\n3) Выход из пополнения\n";
        cout << "\nВыбор: ";
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
        cout << "\nНеправильная операция. Повторите выбор.\n";
        PauseAndClear();
        PopUpBalance(user);
        break;
    }
    return user.balance;
}
#endif


int main() {
    setlocale(LC_ALL, "RU");

    int now_index = 1; BankUser user;
    WelcomeMenu(user, now_index);

    return 0;
}