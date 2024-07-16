class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int T1 = nums[0];
        int H1 = nums[0];

      
        do {
            T1 = nums[T1];
            H1 = nums[nums[H1]];
        } while (T1 != H1);

       
        T1 = nums[0];
        while (T1 != H1) {
            T1 = nums[T1];
            H1 = nums[H1];
        }

        
        return H1;
    }
};
