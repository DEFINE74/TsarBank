#include "user.h"

BankUser::BankUser() {
	this->is_registered = true;
	this->balance = 0;
}

BankUser::BankUser(std::string login, std::string password) {
	this->login = login;
	this->password = password;
	this->is_registered = true; 
	this->balance = 0;
}

void BankUser::SetLogin(std::string login) {
	this->login = login;
}
void BankUser::SetPassword(std::string password) {
	this->password = password;
}