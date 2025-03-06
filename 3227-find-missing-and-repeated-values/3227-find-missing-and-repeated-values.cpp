class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int missing, repeat =0;

        unordered_map<int, int> freq;
        for(auto &row : grid){
            for(int num : row){
                freq[num]++;
            }
        }

        for(int num =1; num<=n*n; num++){
            if(!freq.count(num)) missing = num;
            else if(freq[num]==2) repeat = num;
        }
        return {repeat, missing};
    }
};