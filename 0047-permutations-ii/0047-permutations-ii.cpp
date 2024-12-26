class Solution {
public:

    void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& used) {
        // Base case: if the current permutation is complete
        if (current.size() == nums.size() && find(result.begin(), result.end(), current) == result.end()) {
            result.push_back(current);
            return;
        }

        // Iterate through all elements in nums
        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue; // Skip if already used

            // Mark the element as used and add to current permutation
            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, result, current, used);

            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result; 
        vector<int> current;       
        vector<bool> used(nums.size(), false); 
        sort(nums.begin(), nums.end());
        backtrack(nums, result, current, used);
        return result;
    }
};