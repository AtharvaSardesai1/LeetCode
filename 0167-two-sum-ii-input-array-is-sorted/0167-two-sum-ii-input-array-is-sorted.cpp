class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int, int> Table;
        int n = numbers.size();

        for (int i=0; i<n ; i++){
            int complement = target - numbers[i];

            if(Table.find(complement) != Table.end())
                return {Table[complement]+1, i+1};
            
            Table[numbers[i]] = i;
        }
        return {};
    }
};