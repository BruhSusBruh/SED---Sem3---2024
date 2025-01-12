#include <iostream>
#include "../Header/File.h"

void File::saveUsers(const std::vector<User *> &users, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &user : users) {
            file << user->getUsername() << ","
                 << user->getPassword() << ","
                 << user->getFullName() << ","
                 << user->getPhone() << ","
                 << user->getEmail() << ","
                 << user->getCreditPoints() << ","
                 << user->getRating() << "\n";
        }
        file.close();
        std::cout << "Users saved successfully.\n";
    } else {
        std::cerr << "Failed to open file for saving users.\n";
    }
}

std::vector<User *> File::loadUsers(const std::string &filename) {
    std::vector<User *> users;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string username, password, fullName, phone, email;
            int creditPoints;
            float rating;

            std::getline(ss, username, ',');
            std::getline(ss, password, ',');
            std::getline(ss, fullName, ',');
            std::getline(ss, phone, ',');
            std::getline(ss, email, ',');
            ss >> creditPoints;
            ss.ignore();
            ss >> rating;

            users.push_back(new User(username, password, fullName, phone, email, "", ""));
        }
        file.close();
        std::cout << "Users loaded successfully.\n";
    } else {
        std::cerr << "Failed to open file for loading users.\n";
    }
    return users;
}

void File::saveItems(const std::vector<Item> &items, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &item : items) {
            file << item.getName() << ","
                 << item.getCategory() << ","
                 << item.getDescription() << ","
                 << item.getStartingBid() << ","
                 << item.getCurrentBid() << ","
                 << item.getCurrentBidder() << "\n";
        }
        file.close();
        std::cout << "Items saved successfully.\n";
    } else {
        std::cerr << "Failed to open file for saving items.\n";
    }
}

std::vector<Item> File::loadItems(const std::string &filename) {
    std::vector<Item> items;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string name, category, description, currentBidder;
            double startingBid, currentBid;

            std::getline(ss, name, ',');
            std::getline(ss, category, ',');
            std::getline(ss, description, ',');
            ss >> startingBid;
            ss.ignore();
            ss >> currentBid;
            ss.ignore();
            std::getline(ss, currentBidder, ',');

            items.emplace_back(name, category, description, startingBid, 0, 0, "", "");
        }
        file.close();
        std::cout << "Items loaded successfully.\n";
    } else {
        std::cerr << "Failed to open file for loading items.\n";
    }
    return items;
}

void File::saveAuctions(const std::vector<Auction> &auctions, const std::string &filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto &auction : auctions) {
            file << auction.getAuctionID() << ",";
            file << auction.getItem().getName() << "\n";
        }
        file.close();
        std::cout << "Auctions saved successfully.\n";
    } else {
        std::cerr << "Failed to open file for saving auctions.\n";
    }
}

std::vector<Auction> File::loadAuctions(const std::string &filename) {
    std::vector<Auction> auctions;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string auctionID, itemName;
            std::getline(ss, auctionID, ',');
            std::getline(ss, itemName, ',');
            auctions.emplace_back(auctionID, Item(itemName, "", "", 0, 0, 0, "", ""));
        }
        file.close();
        std::cout << "Auctions loaded successfully.\n";
    } else {
        std::cerr << "Failed to open file for loading auctions.\n";
    }
    return auctions;
}