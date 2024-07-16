#include <vector>
#include <unordered_map>

class Solution {
public:
    int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> prefix_count;
        prefix_count[0] = 1; 
        int sum = 0, result = 0;
        
        for (int num : nums) {
            sum += num;
            int mod = ((sum % k) + k) % k;  
            if (prefix_count.find(mod) != prefix_count.end()) {
                result += prefix_count[mod];
            }
            prefix_count[mod]++;
        }
        
        return result;
    }
};
