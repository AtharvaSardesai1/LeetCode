class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string , vector<string>> map;
        string temp;

        for(int i=0; i<n; i++){
            temp = strs[i];
            sort(strs[i].begin(), strs[i].end());
            map[strs[i]].push_back(temp);
        }

        vector<vector<string>> result;

        for(auto i=map.begin(); i!= map.end(); i++){
            result.push_back(i->second);
        }
        return result;
        
    }
};