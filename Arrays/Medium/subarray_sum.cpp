#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // There's one way to get a sum of 0 (by not taking any element)
        
        int currentSum = 0;
        int totalCount = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            currentSum += nums[i];
            int requiredSum = currentSum - k;
            
            if (prefixSumCount.find(requiredSum) != prefixSumCount.end()) {
                totalCount += prefixSumCount[requiredSum];
            }
            
            prefixSumCount[currentSum]++;
        }
        
        return totalCount;
    }
};
