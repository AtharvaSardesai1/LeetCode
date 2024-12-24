class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> Table;
        
        for(int i=0; i<nums.size(); i++){
            int complement = target - nums[i];
            
            if(Table.find(complement)!= Table.end()){
                return {Table[complement],i};
                
            }
            Table[nums[i]]=i;
        }
        return {};
    }
};