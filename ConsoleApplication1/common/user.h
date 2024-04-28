#ifndef H_USER
#define H_USER

#include <string>

class BankUser {
private:
    std::string login, password;
public:
    BankUser();
    BankUser(std::string login, std::string password);

    inline std::string GetLogin() { return login; }

    bool is_registered; double balance;
    
    void SetLogin(std::string);
    void SetPassword(std::string);
}; 
#endif