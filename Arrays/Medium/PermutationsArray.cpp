class Solution {
public:
    void backtrack(std::vector<int>& arr, int start, std::set<std::vector<int>>& uniquePerms) {
        if (start == arr.size()) {
            uniquePerms.insert(arr);
            return;
        }
        for (int i = start; i < arr.size(); ++i) {
            std::swap(arr[start], arr[i]);
            backtrack(arr, start + 1, uniquePerms);
            std::swap(arr[start], arr[i]);
        }
    }
    
    std::vector<std::vector<int>> uniquePerms(std::vector<int>& arr, int n) {
        std::set<std::vector<int>> uniquePerms;
        backtrack(arr, 0, uniquePerms);
        
        std::vector<std::vector<int>> result(uniquePerms.begin(), uniquePerms.end());
        return result;
    }
};