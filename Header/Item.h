// // Item.h
// #ifndef ITEM_H
// #define ITEM_H

// #include <iostream>
// #include <iomanip>
// #include <string>
// #include <vector>
// #include <ctime>
// #include <fstream>
// #include <sstream>
// #include <ios>
// #include "User.h"



// using namespace std;

// class Item
// {
// private:
//     int id;               // Unique identifier for the item
//     string name;          // Name of the item
//     string category;      // Category to which the item belongs
//     string description;   // Short description of the item
//     int startingBid;      // Starting bid amount in credit points (CP)
//     int bidIncrement;     // Minimum increment for subsequent bids in CP
//     int currentBid;       // Current highest bid amount in CP
//     string currentBidder; // Username of the current highest bidder
//     string seller;        // Username of the seller
//     string startDateTime; // Start date and time of the auction
//     string endDateTime;   // End date and time of the auction
//     int minBuyerRating;   // Minimum rating required for buyers to bid
//     bool hasActiveBids;   // Flag indicating if there are active bids on the item
// public:
//     friend class User;
    
//     static string getCurrentDateTime()
//     {
//         time_t now = time(0);
//         tm *ltm = localtime(&now);
//         char buffer[20];
//         strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", ltm);
//         return string(buffer);
//     }

//     // Item listing display format
//     void displayItem() const
//     {
//         cout << left << setw(5) << id
//              << setw(25) << name
//              << setw(15) << category
//              << setw(15) << currentBid
//              << setw(15) << currentBidder
//              << setw(15) << endDateTime << "\n";
//     }

//     bool isExpired() const
//     {
//         std::tm tm = {};
//         std::istringstream ss(endDateTime);
//         ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
//         if (ss.fail())
//         {
//             return false; // If the date format is invalid, consider it not expired
//         }
//         time_t end_time = mktime(&tm);
//         time_t now = time(0);
//         return difftime(now, end_time) > 0;
//     }
//     // Display all items in the system
//     void displayItemListing(const vector<Item> &items)
//     {
//         cout << "\nItem Listings:\n";
//         cout << "-----------------------------------------------------------------------------------------\n";
//         cout << left << setw(5) << "ID"
//              << setw(25) << "Name"
//              << setw(15) << "Category"
//              << setw(15) << "Current Bid"
//              << setw(15) << "Current Bidder"
//              << setw(15) << "End Date" << "\n";
//         for (const auto &item : items)
//         {
//             item.displayItem();
//         }
//     }

//     // Display active items listed by the member
//     void displayActiveSellItems(const User &member, const vector<Item> &items)
//     {
//         cout << "\nActive Current Listings:\n";
//         cout << "-----------------------------------------------------------------------------------------\n";
//         cout << left << setw(5) << "No."
//              << setw(25) << "Name"
//              << setw(15) << "Category"
//              << setw(15) << "Current Bid"
//              << setw(15) << "Current Bidder"
//              << setw(25) << "End Date & Time" << "\n";
//         int count = 1;
//         for (const auto &item : items)
//         {
//             if ((item.seller == member.username) && !item.isExpired())
//             {
//                 cout << left << setw(5) << count++
//                      << setw(25) << item.name
//                      << setw(15) << item.category
//                      << setw(15) << item.currentBid
//                      << setw(15) << item.currentBidder
//                      << setw(25) << item.endDateTime << "\n";
//             }
//         }
//     }

//     // Display active items on which the member has placed bids
//     void displayActiveCurrentBids(const User &member, const vector<Item> &items)
//     {
//         cout << "\nActive Current Bids:\n";
//         cout << "-----------------------------------------------------------------------------------------\n";
//         cout << left << setw(5) << "No."
//              << setw(25) << "Name"
//              << setw(15) << "Category"
//              << setw(15) << "Current Bid"
//              << setw(15) << "Current Bidder"
//              << setw(25) << "End Date & Time" << "\n";
//         int count = 1;
//         for (const auto &item : items)
//         {
//             if ((item.currentBidder == member.username) && !item.isExpired())
//             {
//                 cout << left << setw(5) << count++
//                      << setw(25) << item.name
//                      << setw(15) << item.category
//                      << setw(15) << item.currentBid
//                      << setw(15) << item.currentBidder
//                      << setw(25) << item.endDateTime << "\n";
//             }
//         }
//     }

//     // Load items from txt file
//     void loadItems(vector<Item> &items)
//     {
//         std::ifstream file("items.txt", std::ios::in);
//         if (file.is_open())
//         {
//             Item item;
//             while (file >> item.id >> item.name >> item.category >> item.description >> item.startingBid >> item.bidIncrement >> item.currentBid >> item.currentBidder >> item.seller >> item.startDateTime >> item.endDateTime >> item.minBuyerRating >> item.hasActiveBids)
//             {
//                 items.push_back(item);
//             }
//             file.close();
//         }
//     }

//     // Save items to txt file
//     void saveItemToFile(const Item &item)
//     {
//         std::ofstream file("items.txt", std::ios::app);
//         if (file.is_open())
//         {
//             file << item.id << " " << item.name << " " << item.category << " " << item.description << " "
//                  << item.startingBid << " " << item.bidIncrement << " " << item.currentBid << " "
//                  << item.currentBidder << " " << item.seller << " " << item.startDateTime << " "
//                  << item.endDateTime << " " << item.minBuyerRating << " " << item.hasActiveBids << "\n";
//             file.close();
//         }
//         else
//         {
//             cout << "Error: Unable to save item to file.\n";
//         }
//     }

//     // Add a new item listing
//     void addListing(User &seller, vector<Item> &items)
//     {
//         Item newItem;
//         newItem.seller = seller.username; // Set the seller of the item to the logged in user
//         newItem.id = items.size() + 1;    // Generate a new ID based on the size of the items vector
//         cout << "Enter item name: ";
//         cin >> newItem.name; // Read the item name from the user
//         cout << "Enter item category: ";
//         cin >> newItem.category; // Read the item category from the user
//         cout << "Enter item description: ";
//         cin.ignore();
//         getline(cin, newItem.description); // Read the item description from the user
//         cout << "Enter starting bid: ";
//         while (!(cin >> newItem.startingBid)) // Read the starting bid amount from the user
//         {
//             cout << "Invalid input. Please enter a valid starting bid: ";
//             cin.clear();
//             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         }
//         cout << "Enter bid increment: ";
//         while (!(cin >> newItem.bidIncrement)) // Read the bid increment amount from the user
//         {
//             cout << "Invalid input. Please enter a valid bid increment: ";
//             cin.clear();
//             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         }
//         cout << "Enter minimum buyer rating: ";
//         while (!(cin >> newItem.minBuyerRating)) // Read the minimum buyer rating from the user
//         {
//             cout << "Invalid input. Please enter a valid minimum buyer rating: ";
//             cin.clear();
//             cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//         }
//         newItem.currentBid = newItem.startingBid; // Set the current bid to the starting bid
//         newItem.currentBidder = "";
//         newItem.startDateTime = Item::getCurrentDateTime(); // Set the start date and time to the current date and time
//         cout << "Enter end date and time (YYYY-MM-DD HH:MM:SS): ";
//         cin.ignore();
//         getline(cin, newItem.endDateTime); // Read the end date and time from the user

//         // Validate end date and time format
//         std::tm tm = {};
//         std::istringstream ss(newItem.endDateTime);
//         ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
//         while (ss.fail())
//         {
//             cout << "Invalid date and time format. Please enter in the format YYYY-MM-DD HH:MM:SS.\n";
//             cin.clear();
//             getline(cin, newItem.endDateTime);
//         }

//         newItem.hasActiveBids = false;

//         items.push_back(newItem);
//         saveItemToFile(newItem);

//         cout << "Item listed successfully!\n";
//     }

//     // Edit an existing item listing
//     void editListing(User &seller, vector<Item> &items)
//     {
//         int itemId;
//         cout << "Enter the ID of the item you want to edit: ";
//         cin >> itemId;

//         for (auto &item : items)
//         {
//             if (item.id == itemId)
//             {
//                 if (item.hasActiveBids)
//                 {
//                     cout << "Cannot edit item with active bids.\n";
//                     return;
//                 }
//                 cout << "Enter new item name: ";
//                 cin >> item.name;
//                 cout << "Enter new item category: ";
//                 cin >> item.category;
//                 cout << "Enter new item description: ";
//                 cin.ignore();
//                 getline(cin, item.description);
//                 cout << "Enter new starting bid: ";
//                 cin >> item.startingBid;
//                 cout << "Enter new bid increment: ";
//                 cin >> item.bidIncrement;
//                 cout << "Enter new end date and time (YYYY-MM-DD HH:MM:SS): ";
//                 cin.ignore();
//                 getline(cin, item.endDateTime);
//                 cout << "Enter new minimum buyer rating: ";
//                 cin >> item.minBuyerRating;

//                 cout << "Item edited successfully!\n";
//                 return;
//             }
//         }
//         cout << "Item not found.\n";
//     }

//     // Remove an existing item listing
//     void removeListing(User &seller, vector<Item> &items)
//     {
//         int itemId;
//         cout << "Enter the ID of the item you want to remove: ";
//         cin >> itemId;

//         for (auto it = items.begin(); it != items.end(); ++it)
//         {
//             if (it->id == itemId)
//             {
//                 if (it->hasActiveBids)
//                 {
//                     cout << "Cannot remove item with active bids.\n";
//                     return;
//                 }
//                 items.erase(it);
//                 cout << "Item removed successfully!\n";
//                 return;
//             }
//         }
//         cout << "Item not found.\n";
//     }

//     // Get details of a specific item
//     void getItemDetails(const vector<Item> &items, int itemId)
//     {
//         for (const auto &item : items)
//         {
//             if (item.id == itemId)
//             {
//                 cout << "Item ID: " << item.id << "\n"
//                      << "Name: " << item.name << "\n"
//                      << "Category: " << item.category << "\n"
//                      << "Description: " << item.description << "\n"
//                      << "Starting Bid: " << item.startingBid << "\n"
//                      << "Bid Increment: " << item.bidIncrement << "\n"
//                      << "Current Bid: " << item.currentBid << "\n"
//                      << "Current Bidder: " << item.currentBidder << "\n"
//                      << "Start Date and Time: " << item.startDateTime << "\n"
//                      << "End Date and Time: " << item.endDateTime << "\n"
//                      << "Minimum Buyer Rating: " << item.minBuyerRating << "\n"
//                      << "Has Active Bids: " << (item.hasActiveBids ? "Yes" : "No") << "\n";
//                 return;
//             }
//         }
//         cout << "Item not found.\n";
//     }

//     // Place a bid on an item
//     void placeBid(User &buyer, vector<Item> &items)
//     {
//         int itemId;
//         int bidAmount;
//         cout << "Enter the ID of the item you want to bid on: ";
//         cin >> itemId;

//         for (auto &item : items)
//         {
//             if (item.id == itemId)
//             {
//                 if (buyer.rating < item.minBuyerRating)
//                 {
//                     cout << "Your rating is too low to bid on this item.\n";
//                     return;
//                 }
//                 cout << "Enter your bid amount: ";
//                 cin >> bidAmount;
//                 if (bidAmount < item.currentBid + item.bidIncrement)
//                 {
//                     cout << "Bid amount is too low.\n";
//                     return;
//                 }
//                 item.currentBid = bidAmount;
//                 item.currentBidder = buyer.username;
//                 item.hasActiveBids = true;

//                 cout << "Bid placed successfully!\n";
//                 return;
//             }
//         }
//         cout << "Item not found.\n";
//     }

//     // // Display the member menu with item listing options
//     // void displayMemberMenu(User &loggedInUser, vector<Item> &items)
//     // {
//     //     int option;
//     //     displayActiveCurrentBids(loggedInUser, items);
//     //     displayActiveSellItems(loggedInUser, items);
//     //     do
//     //     {
//     //         cout << "\nMenu Options:\n";
//     //         cout << "1. View profile\n";
//     //         cout << "2. Update profile\n";
//     //         cout << "3. Top up credit points\n";
//     //         cout << "4. View all items\n";
//     //         cout << "5. Add listing\n";
//     //         cout << "6. Remove listing\n";
//     //         cout << "7. Edit listing\n";
//     //         cout << "8. Place bid\n";
//     //         cout << "9. Get item details\n";
//     //         cout << "0. Exit\n";
//     //         cout << "Enter your choice: ";
//     //         cin >> option;

//     //         switch (option)
//     //         {
//     //         case 1:
//     //             loggedInUser.viewProfile();
//     //             break;
//     //         case 2:
//     //             loggedInUser.updateProfile();
//     //             break;
//     //         case 3:
//     //             loggedInUser.topUpCreditPoints();
//     //             break;
//     //         case 4:
//     //             displayItemListing(items);
//     //             break;
//     //         case 5:
//     //             addListing(loggedInUser, items);
//     //             break;
//     //         case 6:
//     //             removeListing(loggedInUser, items);
//     //             break;
//     //         case 7:
//     //             editListing(loggedInUser, items);
//     //             break;
//     //         case 8:
//     //             placeBid(loggedInUser, items);
//     //             break;
//     //         case 9:
//     //         {
//     //             int itemId;
//     //             cout << "Enter the ID of the item: ";
//     //             cin >> itemId;
//     //             getItemDetails(items, itemId);
//     //             break;
//     //         }
//     //         case 0:
//     //             cout << "Exiting...\n";
//     //             break;
//     //         default:
//     //             cout << "Invalid option. Please try again.\n";
//     //         }
//     //     } while (option != 0);
//     // };
// };
// #endif // ITEM_H


// File: Item.h
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <iostream>

class Item {
private:
    std::string name;
    std::string category;
    std::string description;
    double startingBid;
    double bidIncrement;
    int minBuyerRating;
    std::string startTime;
    std::string endTime;
    double currentBid;
    std::string currentBidder;

public:
    // Constructor
    Item(const std::string &name, const std::string &category, const std::string &description,
         double startingBid, double bidIncrement, int minBuyerRating,
         const std::string &startTime, const std::string &endTime);

    // Accessors and Mutators
    std::string getName() const;
    void setName(const std::string &name);

    std::string getCategory() const;
    void setCategory(const std::string &category);

    std::string getDescription() const;
    void setDescription(const std::string &description);

    double getStartingBid() const;
    void setStartingBid(double bid);

    double getBidIncrement() const;
    void setBidIncrement(double increment);

    int getMinBuyerRating() const;
    void setMinBuyerRating(int rating);

    std::string getStartTime() const;
    void setStartTime(const std::string &time);

    std::string getEndTime() const;
    void setEndTime(const std::string &time);

    double getCurrentBid() const;
    void setCurrentBid(double bid);

    std::string getCurrentBidder() const;
    void setCurrentBidder(const std::string &bidder);

    // Other Methods
    void updateDetails(const std::string &newDescription, double newStartingBid, double newBidIncrement);
    void placeBid(const std::string &bidder, double bidAmount);
    void finalizeAuction();

    void displayItemDetails() const;
};

#endif // ITEM_H