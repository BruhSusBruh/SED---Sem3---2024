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