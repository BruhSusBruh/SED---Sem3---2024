#include "./Header/Seller.h"
#include <iostream>

using namespace std;

// Constructor
Seller::Seller(const string& username, const string& fullName)
    : username(username), fullName(fullName) {}

// Create a new item listing
void Seller::createListing(const string& itemName, const string& category,
                           const string& description, int startBid, int bidIncrement, 
                           const string& endTime, float minBuyerRating) {
    ItemListing newListing(itemName, category, description, startBid, bidIncrement, endTime, minBuyerRating);
    listings.push_back(newListing);
    cout << "Listing created successfully for item: " << itemName << endl;
}

// Edit an existing item listing
void Seller::editListing(int listingID, const string& newDescription, int newStartBid,
                         int newBidIncrement, const string& newEndTime, float newMinBuyerRating) {
    for (auto& listing : listings) {
        if (listing.getID() == listingID && !listing.hasActiveBids()) {
            listing.setDescription(newDescription);
            listing.setStartBid(newStartBid);
            listing.setBidIncrement(newBidIncrement);
            listing.setEndTime(newEndTime);
            listing.setMinBuyerRating(newMinBuyerRating);
            cout << "Listing updated successfully.\n";
            return;
        }
    }
    cout << "Error: Listing not found or it has active bids.\n";
}

// Remove an item listing
void Seller::removeListing(int listingID) {
    for (auto it = listings.begin(); it != listings.end(); ++it) {
        if (it->getID() == listingID && !it->hasActiveBids()) {
            listings.erase(it);
            cout << "Listing removed successfully.\n";
            return;
        }
    }
    cout << "Error: Listing not found or it has active bids.\n";
}

// Finalize an auction
void Seller::finalizeAuction(int listingID) {
    for (auto& listing : listings) {
        if (listing.getID() == listingID) {
            if (listing.isAuctionEnded()) {
                int finalBid = listing.getCurrentBid();
                string winner = listing.getCurrentBidder();
                cout << "Auction finalized. Winner: " << winner << ", Final Bid: " << finalBid << " CP.\n";
                // Logic to transfer credits can be added here
                return;
            } else {
                cout << "Error: Auction is still active.\n";
                return;
            }
        }
    }
    cout << "Error: Listing not found.\n";
}

// Optional: View all listings of the seller
void Seller::viewListings() const {
    for (const auto& listing : listings) {
        listing.displayDetails(); // Assuming ItemListing has a method to display details
    }
}
