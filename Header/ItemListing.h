#ifndef ITEMLISTING_H
#define ITEMLISTING_H

#include <string>

using namespace std;

class ItemListing {
private:
    static int nextID; // Static member for unique IDs
    int id;
    string itemName;
    string category;
    string description;
    int startBid;
    int bidIncrement;
    string endTime;
    float minBuyerRating;
    int currentBid;
    string currentBidder;
    bool activeBids;

public:
    ItemListing(const string& itemName, const string& category,
                const string& description, int startBid, int bidIncrement, 
                const string& endTime, float minBuyerRating);

    int getID() const;
    bool hasActiveBids() const;
    bool isAuctionEnded() const;
    int getCurrentBid() const;
    string getCurrentBidder() const;

    void setDescription(const string& description);
    void setStartBid(int startBid);
    void setBidIncrement(int bidIncrement);
    void setEndTime(const string& endTime);
    void setMinBuyerRating(float minBuyerRating);

    void displayDetails() const; // Display item details
};

#endif
