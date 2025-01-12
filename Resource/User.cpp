// File: User.cpp
#include <iostream>
#include <regex>
#include "../Header/User.h"
#include "User.h"

User::User() : creditPoints(0), rating(3.0) {}

User::User(const std::string &username, const std::string &password, const std::string &fullName,
           const std::string &phone, const std::string &email, const std::string &idType, const std::string &idNumber)
    : username(username), password(password), fullName(fullName), phone(phone), email(email), idType(idType), idNumber(idNumber), creditPoints(0), rating(3.0) {}

std::string User::getUsername() const { return username; }
void User::setUsername(const std::string &username) { this->username = username; }

std::string User::getPassword() const { return password; }
void User::setPassword(const std::string &password) { this->password = password; }

void User::updateProfile(const std::string &newPhone, const std::string &newEmail) {
    phone = newPhone;
    email = newEmail;
}

void User::topUpCredits(int amount) {
    if (amount > 0) {
        creditPoints += amount;
        std::cout << "Credits topped up by " << amount << ". Total: " << creditPoints << "\n";
    } else {
        std::cout << "Invalid top-up amount.\n";
    }
}

bool User::validatePassword(const std::string &password) {
    return password.length() >= 8 && std::regex_search(password, std::regex("[!@#$%^&*]"));
}

void User::displayProfile() const {
    std::cout << "Username: " << username << "\n"
              << "Full Name: " << fullName << "\n"
              << "Phone: " << phone << "\n"
              << "Email: " << email << "\n"
              << "Credit Points: " << creditPoints << "\n"
              << "Rating: " << rating << "\n";
}

User::~User() {}