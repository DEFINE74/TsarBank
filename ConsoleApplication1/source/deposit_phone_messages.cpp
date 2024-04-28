#include <iostream>
#include <string>

#include "other.h"
#include "user.h"

using std::string, std::cout, std::endl;

void DepositPhoneMessage() {
    ClearConsole(); TsarBankMessage();
    cout << "���������� �� ��������." << endl;
    cout << endl << "������� ����� �������� (��������� ������: ������, ��������, ����, �����): ";
}

void PhoneNumberError() {
    cout << endl << "�������� ����� ��������. ������� � �����..." << endl;
    PauseAndClear();
}
void ShowCountryMessage(const double comission, const std::string country) {
    cout << endl << "������ ������ �������� - '" << country << "'." << " ���� �������� ����������: " << comission * 100 << "%." << endl;
}