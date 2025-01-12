#include <iostream>
#include "../Header/Item.h"

Item::Item(const std::string &name, const std::string &category, const std::string &description,
           double startingBid, double bidIncrement, int minBuyerRating,
           const std::string &startTime, const std::string &endTime)
    : name(name), category(category), description(description),
      startingBid(startingBid), bidIncrement(bidIncrement), minBuyerRating(minBuyerRating),
      startTime(startTime), endTime(endTime), currentBid(0), currentBidder("") {}

std::string Item::getName() const { return name; }
void Item::setName(const std::string &name) { this->name = name; }

std::string Item::getCategory() const { return category; }
void Item::setCategory(const std::string &category) { this->category = category; }

std::string Item::getDescription() const { return description; }
void Item::setDescription(const std::string &description) { this->description = description; }

double Item::getStartingBid() const { return startingBid; }
void Item::setStartingBid(double bid) { startingBid = bid; }

double Item::getBidIncrement() const { return bidIncrement; }
void Item::setBidIncrement(double increment) { bidIncrement = increment; }

int Item::getMinBuyerRating() const { return minBuyerRating; }
void Item::setMinBuyerRating(int rating) { minBuyerRating = rating; }

std::string Item::getStartTime() const { return startTime; }
void Item::setStartTime(const std::string &time) { startTime = time; }

std::string Item::getEndTime() const { return endTime; }
void Item::setEndTime(const std::string &time) { endTime = time; }

double Item::getCurrentBid() const { return currentBid; }
void Item::setCurrentBid(double bid) { currentBid = bid; }

std::string Item::getCurrentBidder() const { return currentBidder; }
void Item::setCurrentBidder(const std::string &bidder) { currentBidder = bidder; }

void Item::updateDetails(const std::string &newDescription, double newStartingBid, double newBidIncrement) {
    description = newDescription;
    startingBid = newStartingBid;
    bidIncrement = newBidIncrement;
}

void Item::placeBid(const std::string &bidder, double bidAmount) {
    if (bidAmount >= currentBid + bidIncrement) {
        currentBid = bidAmount;
        currentBidder = bidder;
    } else {
        std::cout << "Bid too low!\n";
    }
}

void Item::finalizeAuction() {
    std::cout << "Auction finalized for item: " << name << "\n";
    std::cout << "Winner: " << currentBidder << " with bid: " << currentBid << "\n";
}

void Item::displayItemDetails() const {
    std::cout << "Item Name: " << name << "\n";
    std::cout << "Category: " << category << "\n";
    std::cout << "Description: " << description << "\n";
    std::cout << "Starting Bid: " << startingBid << "\n";
    std::cout << "Current Bid: " << currentBid << "\n";
    std::cout << "Current Bidder: " << (currentBidder.empty() ? "None" : currentBidder) << "\n";
}