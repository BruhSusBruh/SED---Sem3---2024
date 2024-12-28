#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class User {
private:
    string username;
    string password;
    string fullName;
    string phoneNumber;
    string email;
    string idType;
    string idNumber;
    float rating;
    int creditPoints;

    static unordered_map<string, User> users; // Stores all registered users (username -> User)

    // Helper functions
    static bool isValidPassword(const string& password); // Strong password validation
    static bool isUsernameTaken(const string& username);

public:
    // Constructor
    User(const string& username, const string& password, const string& fullName,
         const string& phoneNumber, const string& email, const string& idType, const string& idNumber);

    // Static functions for login and signup
    static bool signup(const string& username, const string& password, const string& fullName,
                       const string& phoneNumber, const string& email, const string& idType, const string& idNumber);

    static User* login(const string& username, const string& password);

    // Getters for user details
    string getUsername() const;
    string getFullName() const;
    float getRating() const;
    int getCreditPoints() const;
};

#endif
