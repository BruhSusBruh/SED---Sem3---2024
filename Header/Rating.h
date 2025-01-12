// File: Rating.h
#ifndef RATING_H
#define RATING_H

#include <string>
#include <vector>
#include <numeric>
#include <iostream>

class Rating {
private:
    std::vector<int> buyerRatings;
    std::vector<int> sellerRatings;

public:
    // Add ratings
    void addBuyerRating(int rating);
    void addSellerRating(int rating);

    // Calculate average ratings
    float calculateBuyerAverageRating() const;
    float calculateSellerAverageRating() const;

    // Display ratings
    void displayRatings() const;
};

#endif // RATING_H