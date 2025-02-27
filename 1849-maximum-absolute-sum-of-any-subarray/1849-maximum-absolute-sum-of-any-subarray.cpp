#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxpoint=0, minpoint=0, prefixsum=0;

        for (int i=0; i<nums.size(); i++){
            prefixsum += nums[i];

            maxpoint = max(maxpoint, prefixsum);
            minpoint = min(minpoint, prefixsum);
        }
        return maxpoint-minpoint;
    }

};
