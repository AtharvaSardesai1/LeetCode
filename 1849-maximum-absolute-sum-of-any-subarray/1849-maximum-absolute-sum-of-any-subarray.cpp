#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0, currentMax = 0, currentMin = 0;
        
        for (int num : nums) {
            // Kadane's for max sum subarray
            currentMax = max(num, currentMax + num);
            maxSum = max(maxSum, currentMax);

            // Kadane's for min sum subarray
            currentMin = min(num, currentMin + num);
            minSum = min(minSum, currentMin);
        }
        
        return max(abs(maxSum), abs(minSum));
    }
};
