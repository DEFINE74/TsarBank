#include <iostream>

#include "other.h"

using std::cout, std::endl;

void DepositStartMessage(int& now_index) {
    ClearConsole(); TsarBankMessage();
    cout << "�������� ������ ����������." << endl << endl;
    cout << (now_index == 1 ? "> " : "  ") << "1) ���������� ������ (�������� � ����������� �� �����)" << endl;
    cout << (now_index == 2 ? "> " : "  ") << "2) �� ������ �������� (�������� � ����������� �� ������)" << endl;
    cout << (now_index == 3 ? "> " : "  ") << "3) ����� �� ����������" << endl;
}