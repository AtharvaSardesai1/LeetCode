class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos, neg =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<0) neg++;
            else if(nums[i]==0) continue;
            else pos++;
        }
        return max(pos, neg);
    }
};