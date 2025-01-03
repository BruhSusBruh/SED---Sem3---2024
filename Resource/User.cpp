#include "User.h"
#include <iostream>
#include <regex>

// Initialize the static map
unordered_map<string, User> User::users;

// Constructor
User::User(const string& username, const string& password, const string& fullName,
           const string& phoneNumber, const string& email, const string& idType, const string& idNumber)
    : username(username), password(password), fullName(fullName), phoneNumber(phoneNumber),
      email(email), idType(idType), idNumber(idNumber), rating(3.0), creditPoints(0) {}

// Helper: Validate strong password
bool User::isValidPassword(const string& password) {
    // Strong password: Minimum 8 characters, at least one uppercase letter, one digit, and one special character
    regex passwordPattern("^(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{8,}$");
    return regex_match(password, passwordPattern);
}

// Helper: Check if username is taken
bool User::isUsernameTaken(const string& username) {
    return users.find(username) != users.end();
}

// Signup function
bool User::signup(const string& username, const string& password, const string& fullName,
                  const string& phoneNumber, const string& email, const string& idType, const string& idNumber) {
    if (isUsernameTaken(username)) {
        cout << "Error: Username is already taken.\n";
        return false;
    }

    if (!isValidPassword(password)) {
        cout << "Error: Password must be at least 8 characters long, with one uppercase letter, one digit, and one special character.\n";
        return false;
    }

    // Add the user to the system
    users[username] = User(username, password, fullName, phoneNumber, email, idType, idNumber);
    cout << "Signup successful! Welcome, " << fullName << "!\n";
    return true;
}

// Login function
User* User::login(const string& username, const string& password) {
    auto it = users.find(username);
    if (it != users.end() && it->second.password == password) {
        cout << "Login successful! Welcome back, " << it->second.fullName << "!\n";
        return &it->second; // Return a pointer to the logged-in user
    }

    cout << "Error: Invalid username or password.\n";
    return nullptr;
}

// Getters
string User::getUsername() const {
    return username;
}

string User::getFullName() const {
    return fullName;
}

float User::getRating() const {
    return rating;
}

int User::getCreditPoints() const {
    return creditPoints;
}
