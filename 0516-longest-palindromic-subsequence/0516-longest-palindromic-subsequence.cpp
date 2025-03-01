class Solution {
public:

    int dp[1000][1000];
    string str;

    int solve(int l , int r){
        if (l==r+1) return 0;
        if (l==r) return 1;

        if (dp[l][r]>0){
            return dp[l][r];
        }
        if( str[l]==str[r]){
            dp[l][r] = solve(l+1, r-1) +2;
        }
        dp[l][r] = max(dp[l][r], solve(l+1,r) );
        dp[l][r] = max(dp[l][r], solve(l,r-1));
        return dp[l][r];
    }

    int longestPalindromeSubseq(string s) {
        str = s;
        return solve(0, (int)s.size()-1);
    }
};