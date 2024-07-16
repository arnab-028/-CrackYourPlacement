#include <vector>
#include <unordered_set>

class Solution {
public:
    std::vector<int> findresult(std::vector<int>& nums) {
        std::unordered_set<int> value;
        std::vector<int> result;

        for (int num : nums) {
            if (value.find(num) != value.end()) {
                result.push_back(num);
            } else {
                value.insert(num);
            }
        }

        return result;
    }
};
