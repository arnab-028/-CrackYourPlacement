#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    long long findMinDiff(vector<long long> a, long long n, long long m) {
        // If there are no packets or students
        if (m == 0 || n == 0) {
            return 0;
        }
        
        // If there are fewer packets than students
        if (n < m) {
            return -1;
        }
        
        // Sort the array
        sort(a.begin(), a.end());
        
        // Initialize minimum difference to a large value
        long long min_diff = LLONG_MAX;
        
        // Traverse the sorted array and find the minimum difference
        for (long long i = 0; i <= n - m; i++) {
            long long current_diff = a[i + m - 1] - a[i]; // Max - Min in current window
            if (current_diff < min_diff) {
                min_diff = current_diff;
            }
        }
        
        return min_diff;
    }
};
