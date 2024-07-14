class Solution {
public:
  void moveZeroes(std::vector<int>& nums) {
    int non0 = 0; // Index for non-zero elements

    for (int i = 0; i < nums.size(); i++) {
      
      if (nums[i] != 0) {
        // Swap the current element with the element at nonZeroIdx
        if (i != non0) {
          std::swap(nums[i], nums[non0]);
        }
        non0++; // Increment nonZeroIdx for the next non-zero element
      }
    }
  }
};
