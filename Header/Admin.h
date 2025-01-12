#ifndef ADMIN_H
#define ADMIN_H

#include "User.h"
#include <vector>
#include "Item.h"

class Admin : public User {
public:
    Admin(const std::string &username, const std::string &password, const std::string &fullName,
          const std::string &phone, const std::string &email)
        : User(username, password, fullName, phone, email) {}

    void viewAllUsers(const std::vector<User *> &users) const {
        std::cout << "\nAll Registered Users:\n";
        for (const auto &user : users) {
            std::cout << "Username: " << user->getUsername() << "\n"
                      << "Full Name: " << user->getFullName() << "\n"
                      << "Phone: " << user->getPhone() << "\n"
                      << "Email: " << user->getEmail() << "\n"
                      << "Credit Points: " << user->getCreditPoints() << "\n"
                      << "Rating: " << user->getRating() << "\n\n";
        }
    }

    void viewAllItems(const std::vector<Item> &items) const {
        std::cout << "\nAll Listed Items:\n";
        for (const auto &item : items) {
            item.displayItemDetails();
        }
    }

    ~Admin() {}
};

#endif // ADMIN_H
