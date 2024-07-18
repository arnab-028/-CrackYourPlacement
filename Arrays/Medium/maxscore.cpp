#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        
        if (k == n) return total;

        int windowSize = n - k;
        int minSubarraySum = accumulate(cardPoints.begin(), cardPoints.begin() + windowSize, 0);
        int currentSubarraySum = minSubarraySum;
        
        for (int i = windowSize; i < n; ++i) {
            currentSubarraySum += cardPoints[i] - cardPoints[i - windowSize];
            minSubarraySum = min(minSubarraySum, currentSubarraySum);
        }
        
        return total - minSubarraySum;
    }
};
