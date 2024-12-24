#include <climits>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        int closest = INT_MAX;
        int minDifference = INT_MAX;
        sort(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            if (i>0 && nums[i]==nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while (j<k){
                int sum = nums[i] + nums[j] + nums[k];
                int fourth = abs(target - sum);

                if (fourth < minDifference){
                    minDifference = fourth ;
                    closest = sum;
                }

                if (sum < target) j++;
                else if (sum > target) k--;
                else{
                    
                    j++; 
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while (j<k && nums[k]==nums[k+1]) k--;
                }
            }
        }

    return closest;    
    }
};