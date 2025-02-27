
    class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, int> index;  // Maps value -> index in arr
        vector<vector<int>> dp(n, vector<int>(n, 2)); // Default length is 2
        
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            index[arr[i]] = i;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int target = arr[i] - arr[j];  
                
                if (index.find(target) != index.end() && index[target] < j) {
                    int k = index[target];  
                    dp[j][i] = dp[k][j] + 1;
                    maxLen = max(maxLen, dp[j][i]);
                }
            }
        }

        return maxLen >= 3 ? maxLen : 0;  
    }
};
