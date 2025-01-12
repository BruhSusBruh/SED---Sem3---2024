// File: Customer.cpp
#include "Customer.h"

Customer::Customer() {}

Customer::Customer(const std::string &username, const std::string &password, const std::string &fullName,
                   const std::string &phone, const std::string &email, const std::string &idType, const std::string &idNumber)
    : User(username, password, fullName, phone, email, idType, idNumber) {}

void Customer::searchItems(const std::string &query) {
    std::cout << "Searching for items: " << query << "\n";
    // Logic for searching items
}

void Customer::bidItem(const std::string &itemName, int bidAmount) {
    std::cout << "Placing bid of " << bidAmount << " on item: " << itemName << "\n";
    activeBids.push_back(itemName);
}

void Customer::displayActiveBids() const {
    std::cout << "Active Bids:\n";
    for (const auto &bid : activeBids) {
        std::cout << " - " << bid << "\n";
    }
}

void Customer::displayItemsWon() const {
    std::cout << "Items Won:\n";
    for (const auto &item : itemsWon) {
        std::cout << " - " << item << "\n";
    }
}
Customer::~Customer() {}