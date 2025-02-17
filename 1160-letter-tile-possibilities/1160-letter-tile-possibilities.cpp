class Solution {
public:

    int builder(vector<int>& freq){
        int ways=0;
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                freq[i]--;
                ways += 1+builder(freq);
                freq[i]++;
            }

        }
        return ways;
    }

    int numTilePossibilities(string tiles) {
        vector<int> freq(26,0);
        for(char c : tiles){
            freq[c-'A']++;
        }
        return builder(freq);
    }
};