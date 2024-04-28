#include <iostream>

#include "user.h"
#include "other.h"

using std::cout, std::endl;

void RegisterMessage(int& now_index) {
    ClearConsole();
    cout << "����-���� (�)" << endl;
    cout << endl << "����� ����������, �� �� ����������������." << endl;
    cout << "������ ������������������ ? " << endl << endl;
    cout << (now_index == 1 ? "> " : "  ") << "1) ��\n";
    cout << (now_index == 2 ? "> " : "  ") << "2) ���\n";
}
void LoginAndPasswordMessage() {
    cout << "����-���� (�)" << endl;
    cout << endl << "��� ����������� ��� ����������� ������� ���� ����� � ������. �� ���������� ��������� ��� �����" << endl;
    cout << endl << "�� ������ 10 ��������!" << endl;
    cout << "�����: ";
}
void RegisteredLikeMessage(BankUser& user) {
    cout << endl << "�� ������������������ � ������� ��� " << user.GetLogin();
}