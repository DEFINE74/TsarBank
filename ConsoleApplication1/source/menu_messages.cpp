#include <iostream>

#include "user.h"
#include "other.h"

using std::cout, std::endl;

void InterfaceMessage(BankUser& user,int& now_index) {
    ClearConsole();
    TsarBankMessage();
    cout << "������ ����, " << user.GetLogin() << endl;
    cout << endl << "��� �� ������ ������� �������?" << endl;
    cout << (now_index == 1 ? "> " : "  ") << "1) ������� ������" << endl;
    cout << (now_index == 2 ? "> " : "  ") << "2) ��������� ������" << endl;
    cout << (now_index == 3 ? "> " : "  ") << "3) ������� ��������" << endl;
    cout << (now_index == 4 ? "> " : "  ") << "4) ������� �����" << endl;
    cout << (now_index == 5 ? "> " : "  ") << "5) ��������� ������" << endl;
}
