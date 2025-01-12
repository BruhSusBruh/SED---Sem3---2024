// File: Seller.h
#ifndef SELLER_H
#define SELLER_H

#include "User.h"
#include <vector>
#include <string>

class Seller : public User {
private:
    std::vector<std::string> activeListings;

public:
    Seller();
    Seller(const std::string &username, const std::string &password, const std::string &fullName,
           const std::string &phone, const std::string &email, const std::string &idType, const std::string &idNumber);

    void createListing(const std::string &itemName);
    void editListing(const std::string &itemName, const std::string &newDetails);
    void deleteListing(const std::string &itemName);

    void displayListings() const;

    virtual ~Seller();
};

#endif