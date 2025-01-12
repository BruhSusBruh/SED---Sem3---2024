#ifndef DATAPERSISTENCE_H
#define DATAPERSISTENCE_H

#include "User.h"
#include "Item.h"
#include "Auction.h"
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>

class File {
public:
    // Save and Load Users
    static void saveUsers(const std::vector<User *> &users, const std::string &filename);
    static std::vector<User *> loadUsers(const std::string &filename);

    // Save and Load Items
    static void saveItems(const std::vector<Item> &items, const std::string &filename);
    static std::vector<Item> loadItems(const std::string &filename);

    // Save and Load Auctions
    static void saveAuctions(const std::vector<Auction> &auctions, const std::string &filename);
    static std::vector<Auction> loadAuctions(const std::string &filename);
};

#endif