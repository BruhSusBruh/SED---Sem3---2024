#include <iostream>
#include "../Header/Rating.h"

void Rating::addBuyerRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        buyerRatings.push_back(rating);
    } else {
        std::cout << "Invalid buyer rating. Must be between 1 and 5.\n";
    }
}

void Rating::addSellerRating(int rating) {
    if (rating >= 1 && rating <= 5) {
        sellerRatings.push_back(rating);
    } else {
        std::cout << "Invalid seller rating. Must be between 1 and 5.\n";
    }
}

float Rating::calculateBuyerAverageRating() const {
    if (buyerRatings.empty()) return 0.0;
    return std::accumulate(buyerRatings.begin(), buyerRatings.end(), 0.0f) / buyerRatings.size();
}

float Rating::calculateSellerAverageRating() const {
    if (sellerRatings.empty()) return 0.0;
    return std::accumulate(sellerRatings.begin(), sellerRatings.end(), 0.0f) / sellerRatings.size();
}

void Rating::displayRatings() const {
    std::cout << "Buyer Average Rating: " << calculateBuyerAverageRating() << "\n";
    std::cout << "Seller Average Rating: " << calculateSellerAverageRating() << "\n";
}