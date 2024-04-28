#include <iostream>

#include "other.h"

using std::cout, std::endl, std::string;


void CardNumberError() {
    cout << endl << "�������� ����� �����. ������� � ����� ������..." << endl;
    PauseAndClear();
}
void MoneyAmountError() {
    cout << endl << "������������ �����." << endl << "������� � �����..." << endl << endl;
    PauseAndClear();
}

void EnterSummMessage() {
    cout << endl << "������� �������� ����� (�����: 100 000 ������): ";
}
void PayWithComissionMessage(double comission, double money_summ) {
    cout << "� ������ �������� � ���� " << comission * 100 <<
        "%. ��� ����� ����� ���������: " << money_summ + (money_summ * comission) << " ������" << endl << endl;

}
void WannaDepositMessage(double comission, int& now_index, double money_summ) {
    ClearConsole(); TsarBankMessage();
    cout << "�� ����� ����� � �������: " << money_summ << " ������." << endl;
    PayWithComissionMessage(comission, money_summ);
    cout << (now_index == 1 ? "> " : "  ") << "1) ���������" << endl;
    cout << (now_index == 2 ? "> " : "  ") << "2) ������ ����� ������" << endl;
    cout << (now_index == 3 ? "> " : "  ") << "3) ������� ����" << endl;
}
void DepositCardMessage() {
    ClearConsole(); TsarBankMessage();
    cout << "���������� ������." << endl;
    cout << endl << "������� ����� ����� (���������� ���������� �������� - 16, ���� - 4 �����, ����� ������): ";
}
void SuccessfullDepositMessage(BankUser& user) {
    cout << endl << "�������. �� ����� �����: " << user.balance << " ������" << endl;
}

void ShowComissionMessage(const double comission, const std::string bank_system) {
    cout << "��������� ������� ����� ����� - '" << bank_system << "'." << " ���� �������� ����������: " << comission * 100 << "%." << endl;
}

