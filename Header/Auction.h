// File: Auction.h
#ifndef AUCTION_H
#define AUCTION_H

#include "Item.h"
#include <vector>
#include <string>
#include <iostream>

class Auction {
private:
    std::string auctionID;
    Item item;
    std::vector<std::pair<std::string, double>> bidders; // Pair of bidder username and bid amount

public:
    // Constructor
    Auction(const std::string &auctionID, const Item &item);

    // Accessors
    std::string getAuctionID() const;
    Item getItem() const;

    // Bidding
    void addBid(const std::string &bidder, double bidAmount);
    void resolveAuction();

    // Display
    void displayAuctionDetails() const;
};

#endif // AUCTION_H