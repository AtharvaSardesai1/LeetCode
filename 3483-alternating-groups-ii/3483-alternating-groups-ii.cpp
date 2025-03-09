class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int length = colors.size();
        int result=0, alt=1;
        int lastColor = colors[0];

        for(int i=1; i<length +k-1; i++){
            int index = i%length;
            if(colors[index] == lastColor){
                colors[index]= lastColor;
                alt=1;
                continue;
            }
            else{
                alt++;
                if(alt>=k) result+=1;
                lastColor = colors[index];
            }
        }
        return result;
    }
};