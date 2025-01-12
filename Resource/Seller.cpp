#include <iostream>
#include <algorithm> // For std::find and std::remove
#include "../Header/Seller.h"

Seller::Seller() {}

Seller::Seller(const std::string &username, const std::string &password, const std::string &fullName,
               const std::string &phone, const std::string &email, const std::string &idType, const std::string &idNumber)
    : User(username, password, fullName, phone, email, idType, idNumber) {}

void Seller::createListing(const std::string &itemName) {
    activeListings.push_back(itemName);
    std::cout << "Listing created: " << itemName << "\n";
}

void Seller::editListing(const std::string &itemName, const std::string &newDetails) {
    auto it = std::find(activeListings.begin(), activeListings.end(), itemName);
    if (it != activeListings.end()) {
        *it = newDetails;
        std::cout << "Listing updated: " << newDetails << "\n";
    } else {
        std::cout << "Listing not found.\n";
    }
}

void Seller::deleteListing(const std::string &itemName) {
    auto it = std::remove(activeListings.begin(), activeListings.end(), itemName);
    if (it != activeListings.end()) {
        activeListings.erase(it, activeListings.end());
        std::cout << "Listing deleted: " << itemName << "\n";
    } else {
        std::cout << "Listing not found.\n";
    }
}

void Seller::displayListings() const {
    std::cout << "Active Listings:\n";
    for (const auto &listing : activeListings) {
        std::cout << " - " << listing << "\n";
    }
}

// Destructor definition
Seller::~Seller() {}
