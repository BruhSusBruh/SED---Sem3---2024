#include <iostream>
#include <vector>
#include "../Header/User.h"
#include "../Header/Seller.h"
#include "../Header/Customer.h"
#include "../Header/Item.h"
#include "../Header/Auction.h"
#include "../Header/File.h"

void displayMenu() {
    std::cout << "\nAuction Application Menu:\n";
    std::cout << "1. Register as a User\n";
    std::cout << "2. Login\n";
    std::cout << "3. List Items (Guest View)\n";
    std::cout << "4. Create Item Listing (Seller)\n";
    std::cout << "5. Search Items (Customer)\n";
    std::cout << "6. Place a Bid (Customer)\n";
    std::cout << "7. Resolve Auction (Admin)\n";
    std::cout << "8. View Dashboard\n";
    std::cout << "9. Save and Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::vector<User *> users = File::loadUsers("users.txt");
    std::vector<Item> items = File::loadItems("items.txt");
    std::vector<Auction> auctions = File::loadAuctions("auctions.txt");

    int choice;
    do {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1: {
            std::string username, password, fullName, phone, email;
            std::cout << "Enter Username: ";
            std::cin >> username;
            std::cout << "Enter Password: ";
            std::cin >> password;
            std::cout << "Enter Full Name: ";
            std::cin.ignore();
            std::getline(std::cin, fullName);
            std::cout << "Enter Phone: ";
            std::cin >> phone;
            std::cout << "Enter Email: ";
            std::cin >> email;

            users.push_back(new User(username, password, fullName, phone, email, "", ""));
            std::cout << "User registered successfully!\n";
            break;
        }
        case 2: {
            std::string username, password;
            std::cout << "Enter Username: ";
            std::cin >> username;
            std::cout << "Enter Password: ";
            std::cin >> password;

            bool found = false;
            for (auto user : users) {
                if (user->getUsername() == username && user->getPassword() == password) {
                    std::cout << "Login successful! Welcome, " << username << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Invalid credentials!\n";
            }
            break;
        }
        case 3: {
            std::cout << "Available Items:\n";
            for (const auto &item : items) {
                item.displayItemDetails();
            }
            break;
        }
        case 4: {
            std::string name, category, description;
            double startingBid;
            std::cout << "Enter Item Name: ";
            std::cin.ignore();
            std::getline(std::cin, name);
            std::cout << "Enter Category: ";
            std::getline(std::cin, category);
            std::cout << "Enter Description: ";
            std::getline(std::cin, description);
            std::cout << "Enter Starting Bid: ";
            std::cin >> startingBid;

            items.emplace_back(name, category, description, startingBid, 10, 0, "", "");
            std::cout << "Item listed successfully!\n";
            break;
        }
        case 5: {
            std::string query;
            std::cout << "Enter search query: ";
            std::cin.ignore();
            std::getline(std::cin, query);
            for (const auto &item : items) {
                if (item.getName().find(query) != std::string::npos) {
                    item.displayItemDetails();
                }
            }
            break;
        }
        case 6: {
            std::string itemName, bidder;
            double bidAmount;
            std::cout << "Enter Item Name: ";
            std::cin.ignore();
            std::getline(std::cin, itemName);
            std::cout << "Enter Bid Amount: ";
            std::cin >> bidAmount;
            std::cout << "Enter Your Name: ";
            std::cin.ignore();
            std::getline(std::cin, bidder);

            for (auto &auction : auctions) {
                if (auction.getItem().getName() == itemName) {
                    auction.addBid(bidder, bidAmount);
                }
            }
            break;
        }
        case 7: {
            std::string auctionID;
            std::cout << "Enter Auction ID to Resolve: ";
            std::cin >> auctionID;

            for (auto &auction : auctions) {
                if (auction.getAuctionID() == auctionID) {
                    auction.resolveAuction();
                }
            }
            break;
        }
        case 8: {
            std::cout << "Dashboard Summary:\n";
            std::cout << "Total Users: " << users.size() << "\n";
            std::cout << "Total Items: " << items.size() << "\n";
            std::cout << "Total Auctions: " << auctions.size() << "\n";
            break;
        }
        case 9:
            File::saveUsers(users, "users.txt");
            File::saveItems(items, "items.txt");
            File::saveAuctions(auctions, "auctions.txt");
            std::cout << "Data saved. Exiting application.\n";
            break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    // Cleanup dynamically allocated memory
    for (auto user : users) {
        delete user;
    }

    return 0;
}
