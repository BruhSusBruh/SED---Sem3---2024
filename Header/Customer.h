// File: Customer.h
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "User.h"
#include <vector>
#include <string>

class Customer : public User {
private:
    std::vector<std::string> activeBids;
    std::vector<std::string> itemsWon;

public:
    Customer();
    Customer(const std::string &username, const std::string &password, const std::string &fullName,
             const std::string &phone, const std::string &email, const std::string &idType, const std::string &idNumber);

    void searchItems(const std::string &query);
    void bidItem(const std::string &itemName, int bidAmount);

    void displayActiveBids() const;
    void displayItemsWon() const;

    virtual ~Customer();
};

#endif // CUSTOMER_H