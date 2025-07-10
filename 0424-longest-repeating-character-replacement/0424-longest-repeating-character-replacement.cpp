class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> map;
        int left=0;
        int maxFreq=0;
        int maxWindow=0;
        
        for(int right=0; right<s.size(); right++){
            map[s[right]]++;
            maxFreq = max(maxFreq, map[s[right]]);
            int windowSize = right-left+1;
            if(windowSize - maxFreq >k){
                map[s[left]]--;
                maxFreq = max(maxFreq, map[s[right]]);
                windowSize--;
                left++;
            }
            maxWindow = max(windowSize, maxWindow);
        }
        return maxWindow;

    }
};