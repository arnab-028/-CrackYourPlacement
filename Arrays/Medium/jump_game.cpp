class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // The farthest index we can currently reach
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            if (i > maxReach) {
                return false;  // If the current index is beyond the farthest reachable index
            }
            maxReach = max(maxReach, i + nums[i]);
            if (maxReach >= n - 1) {
                return true;  // If we can reach or go beyond the last index
            }
        }
        
        return false;
    }
};
