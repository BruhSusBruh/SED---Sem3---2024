// File: User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>
#include <regex>

class User {
protected:
    std::string username;
    std::string password;
    std::string fullName;
    std::string phone;
    std::string email;
    std::string idType; // Citizen ID or Passport
    std::string idNumber;
    int creditPoints;
    float rating; // Average rating

public:
    User();
    User(const std::string &username, const std::string &password, const std::string &fullName,
         const std::string &phone, const std::string &email, const std::string &idType, const std::string &idNumber);

    // Accessors and Mutators
    std::string getUsername() const;
    void setUsername(const std::string &username);
    
    std::string getPassword() const;
    void setPassword(const std::string &password);

    void updateProfile(const std::string &newPhone, const std::string &newEmail);
    void topUpCredits(int amount);

    static bool validatePassword(const std::string &password);
    void displayProfile() const;

    virtual ~User();
};

#endif // USER_H