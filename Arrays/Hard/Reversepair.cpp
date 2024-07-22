class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
private:
    int mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        int count = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
        count += countAndMerge(nums, left, mid, right);
        return count;
    }
    
    int countAndMerge(vector<int>& nums, int left, int mid, int right) {
        int count = 0;
        int j = mid + 1;
        for (int i = left; i <= mid; ++i) {
            while (j <= right && nums[i] > 2LL * nums[j]) {
                ++j;
            }
            count += (j - (mid + 1));
        }
        
        // Now merge the two halves
        vector<int> temp(right - left + 1);
        int i = left, k = mid + 1, t = 0;
        while (i <= mid && k <= right) {
            if (nums[i] <= nums[k]) {
                temp[t++] = nums[i++];
            } else {
                temp[t++] = nums[k++];
            }
        }
        while (i <= mid) temp[t++] = nums[i++];
        while (k <= right) temp[t++] = nums[k++];
        
        for (int i = left; i <= right; ++i) {
            nums[i] = temp[i - left];
        }
        
        return count;
    }
};
