// User.h
#ifndef USER_H
#define USER_H

#include <string>
#include <iostream>

class User {
protected:
    std::string username;
    std::string password;
    std::string fullName;
    std::string phone;
    std::string email;
    int creditPoints;
    float rating;
    std::string idType;    
    std::string idNumber;

public:
    User();
    User(const std::string &username, const std::string &password, const std::string &fullName, const std::string &phone, const std::string &email, const std::string &idType, const std::string &idNumber);
    void setUsername(const std::string &username);
    void setPassword(const std::string &password);
    void updateProfile(const std::string &newPhone, const std::string &newEmail);
    User(const std::string &username, const std::string &password, const std::string &fullName,
         const std::string &phone, const std::string &email);

    // Getters
    std::string getUsername() const { return username; }
    std::string getPassword() const { return password; }
    std::string getFullName() const { return fullName; }
    std::string getPhone() const { return phone; }
    std::string getEmail() const { return email; }
    int getCreditPoints() const { return creditPoints; }
    float getRating() const { return rating; }
    void topUpCredits(int amount);
    bool validatePassword(const std::string &password);
    void displayProfile() const;
};

#endif // USER_H
