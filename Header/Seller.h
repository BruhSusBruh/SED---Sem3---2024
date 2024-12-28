#ifndef SELLER_H
#define SELLER_H

#include <string>
#include <vector>
#include "ItemListing.h"

using namespace std;

class Seller {
private:
    string username;
    string fullName;
    vector<ItemListing> listings;

public:
    Seller(const string& username, const string& fullName);

    // Function declarations
    void createListing(const string& itemName, const string& category,
                       const string& description, int startBid, int bidIncrement, 
                       const string& endTime, float minBuyerRating);

    void editListing(int listingID, const string& newDescription, int newStartBid,
                     int newBidIncrement, const string& newEndTime, float newMinBuyerRating);

    void removeListing(int listingID);

    void finalizeAuction(int listingID);

    void viewListings() const; // Optional: For viewing all listings of the seller
};

#endif
