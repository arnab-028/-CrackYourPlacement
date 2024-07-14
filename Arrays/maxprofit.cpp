#include <vector>
#include <algorithm> // For std::max
#include <limits> // For std::numeric_limits

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int minPrice = std::numeric_limits<int>::max(); // Initialize to the highest possible value
        int maxProfit = 0; // Initialize max profit to 0

        for (int price : prices) {
            // Update the minimum price
            if (price < minPrice) {
                minPrice = price;
            }
            // Calculate potential profit
            int profit = price - minPrice;
            // Update the maximum profit
            maxProfit = std::max(maxProfit, profit);
        }

        return maxProfit; // Return the maximum profit found
    }
};
