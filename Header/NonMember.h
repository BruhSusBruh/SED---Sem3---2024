#ifndef NONMEMBER_H
#define NONMEMBER_H

#include <iostream>
#include <vector>
#include "Item.h"

class NonMember {
public:
    void viewLimitedItems(const std::vector<Item> &items) const {
        std::cout << "\nGuest View - Limited Item Details:\n";
        for (const auto &item : items) {
            std::cout << "Item Name: " << item.getName() << "\n"
                      << "Category: " << item.getCategory() << "\n"
                      << "Description: " << item.getDescription().substr(0, 50) << "...\n\n";
        }
    }
};

#endif // NONMEMBER_H
