// #include <iostream>
// #include <vector>
// #include <string>
// #include <fstream>
// #include <unordered_map>
// using namespace std;

// struct Item {
//     int id;
//     string name;
//     string category;
//     int currentBid;
//     string currentBidder;
//     string endDateTime;
//     double rating;
//     int bidIncrement = 10; // Default bid increment
// };

// struct BidLimit {
//     string bidder;
//     int limit;
// };

// // Function to read item listings 
// vector<Item> loadListingsFromFile(const string& filename) {
//     vector<Item> items;
//     ifstream file(filename);
//     string line;

//     while (getline(file, line)) {
//         stringstream ss(line);
//         Item item;
//         ss >> item.id;
//         ss.ignore(); // Skip delimiter
//         getline(ss, item.name, ',');
//         getline(ss, item.category, ',');
//         ss >> item.currentBid >> ws;
//         getline(ss, item.currentBidder, ',');
//         getline(ss, item.endDateTime, ',');
//         ss >> item.rating;
//         items.push_back(item);
//     }

//     return items;
// }

// // Function to manage automatic bid limits
// void handleAutomaticBids(Item& item, unordered_map<int, vector<BidLimit>>& bidLimits) {
//     if (bidLimits[item.id].empty()) return;

//     // Sort the bid limits by highest limit
//     sort(bidLimits[item.id].begin(), bidLimits[item.id].end(), [](const BidLimit& a, const BidLimit& b) {
//         return a.limit > b.limit;
//     });

//     for (auto& limit : bidLimits[item.id]) {
//         if (item.currentBid < limit.limit) {
//             item.currentBid += item.bidIncrement;
//             item.currentBidder = limit.bidder;
//         } else {
//             break;
//         }
//     }
// }

// // Function to update bids for a specific item
// void updateBids(vector<Item>& items, unordered_map<int, vector<BidLimit>>& bidLimits, int itemId, int newBid, const string& bidder) {
//     for (auto& item : items) {
//         if (item.id == itemId && newBid > item.currentBid) {
//             item.currentBid = newBid;
//             item.currentBidder = bidder;
//             cout << "Bid updated successfully for item: " << item.name << "\n";
//             handleAutomaticBids(item, bidLimits);
//             return;
//         }
//     }
//     cout << "Invalid bid or item not found.\n";
// }

// // Function to set a bid limit
// void setBidLimit(unordered_map<int, vector<BidLimit>>& bidLimits, int itemId, const string& bidder, int limit, int bidIncrement) {
//     auto& limits = bidLimits[itemId];

//     // Check for conflicting limits
//     for (const auto& existing : limits) {
//         if (existing.limit == limit) {
//             cout << "The bid limit " << limit << " conflicts with another bidder. Suggested limit: " << (limit + bidIncrement) << "\n";
//             return;
//         }
//     }

//     limits.push_back({bidder, limit});
//     cout << "Bid limit set successfully for bidder: " << bidder << "\n";
// }

// // Function to filter items by category
// void filterByCategory(const vector<Item>& items, const string& category) {
//     cout << "Items in category: " << category << "\n";
//     cout << "------------------------------\n";
//     for (const auto& item : items) {
//         if (item.category == category) {
//             cout << item.name << " (Current Bid: $" << item.currentBid << ")\n";
//         }
//     }
//     cout << "\n";
// }

// // Function to filter items by rating
// void filterByRating(const vector<Item>& items, double minRating) {
//     cout << "Items with rating >= " << minRating << "\n";
//     cout << "------------------------------\n";
//     for (const auto& item : items) {
//         if (item.rating >= minRating) {
//             cout << item.name << " (Rating: " << item.rating << ")\n";
//         }
//     }
//     cout << "\n";
// }

// // Function to conclude an auction for a specific item
// void concludeAuction(vector<Item>& items, unordered_map<int, vector<BidLimit>>& bidLimits, int itemId) {
//     for (auto it = items.begin(); it != items.end(); ++it) {
//         if (it->id == itemId) {
//             if (!it->currentBidder.empty()) {
//                 cout << "Auction concluded for item: " << it->name << "\n";
//                 cout << "Winner: " << it->currentBidder << " with a bid of $" << it->currentBid << "\n";
//             } else {
//                 cout << "No bids placed for item: " << it->name << ". Auction ended without a winner.\n";
//             }
//             bidLimits.erase(itemId);
//             items.erase(it);
//             return;
//         }
//     }
//     cout << "Item not found.\n";
// }

// int main() {
//     vector<Item> activeListings = loadListingsFromFile("ItemListing.txt");
//     unordered_map<int, vector<BidLimit>> bidLimits;

//     int choice;
//     do {
//         cout << "Auction System Menu:\n";
//         cout << "1. Display all listings\n";
//         cout << "2. Update a bid\n";
//         cout << "3. Set a bid limit\n";
//         cout << "4. Filter items by category\n";
//         cout << "5. Filter items by rating\n";
//         cout << "6. Conclude an auction\n";
//         cout << "7. Exit\n";
//         cout << "Enter your choice: ";
//         cin >> choice;

//         switch (choice) {
//             case 1: {
//                 cout << "Active Listings:\n";
//                 for (const auto& item : activeListings) {
//                     cout << item.id << ". " << item.name << " | Category: " << item.category
//                          << " | Current Bid: $" << item.currentBid << " | Rating: " << item.rating
//                          << " | Ends: " << item.endDateTime << "\n";
//                 }
//                 cout << "\n";
//                 break;
//             }
//             case 2: {
//                 int itemId, newBid;
//                 string bidder;
//                 cout << "Enter item ID: ";
//                 cin >> itemId;
//                 cout << "Enter your bid: ";
//                 cin >> newBid;
//                 cout << "Enter your name: ";
//                 cin.ignore();
//                 getline(cin, bidder);
//                 updateBids(activeListings, bidLimits, itemId, newBid, bidder);
//                 break;
//             }
//             case 3: {
//                 int itemId, limit;
//                 string bidder;
//                 cout << "Enter item ID: ";
//                 cin >> itemId;
//                 cout << "Enter your name: ";
//                 cin.ignore();
//                 getline(cin, bidder);
//                 cout << "Enter your bid limit: ";
//                 cin >> limit;
//                 setBidLimit(bidLimits, itemId, bidder, limit, activeListings[itemId - 1].bidIncrement);
//                 break;
//             }
//             case 4: {
//                 string category;
//                 cout << "Enter category to filter: ";
//                 cin.ignore();
//                 getline(cin, category);
//                 filterByCategory(activeListings, category);
//                 break;
//             }
//             case 5: {
//                 double minRating;
//                 cout << "Enter minimum rating: ";
//                 cin >> minRating;
//                 filterByRating(activeListings, minRating);
//                 break;
//             }
//             case 6: {
//                 int itemId;
//                 cout << "Enter item ID to conclude auction: ";
//                 cin >> itemId;
//                 concludeAuction(activeListings, bidLimits, itemId);
//                 break;
//             }
//             case 7:
//                 cout << "Exiting system.\n";
//                 break;
//             default:
//                 cout << "Invalid choice. Try again.\n";
//         }
//     } while (choice != 7);

//     return 0;
// }


#include <iostream>
#include "../Header/Auction.h"

Auction::Auction(const std::string &auctionID, const Item &item)
    : auctionID(auctionID), item(item) {}

std::string Auction::getAuctionID() const { return auctionID; }
Item Auction::getItem() const { return item; }

void Auction::addBid(const std::string &bidder, double bidAmount) {
    if (bidAmount > item.getCurrentBid()) {
        item.setCurrentBid(bidAmount);
        item.setCurrentBidder(bidder);
        bidders.push_back({bidder, bidAmount});
        std::cout << "Bid added: " << bidder << " bid " << bidAmount << "\n";
    } else {
        std::cout << "Bid too low to be added.\n";
    }
}

void Auction::resolveAuction() {
    std::cout << "Resolving auction: " << auctionID << "\n";
    if (!bidders.empty()) {
        std::cout << "Winner: " << item.getCurrentBidder() << " with bid: " << item.getCurrentBid() << "\n";
    } else {
        std::cout << "No bids placed for this auction.\n";
    }
}

void Auction::displayAuctionDetails() const {
    std::cout << "Auction ID: " << auctionID << "\n";
    item.displayItemDetails();
    std::cout << "Bidders: \n";
    for (const auto &bidder : bidders) {
        std::cout << " - " << bidder.first << " bid " << bidder.second << "\n";
    }
}