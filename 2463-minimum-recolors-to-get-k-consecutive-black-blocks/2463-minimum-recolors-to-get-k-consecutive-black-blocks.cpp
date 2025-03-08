class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int l=0, r=k-1;
        int black=0, white =0;
        
        for (int i=0; i<k; i++){
            if(blocks[i]=='B') black++;
            else white++;
        }
        int min_change=white;

        while(r<blocks.size()){
            l++,r++;
            if(r==blocks.size()) return min_change;

            if(blocks[l-1]=='W') white--;
            else black --;

            if(blocks[r]=='W') white++;
            else black++;

            if(white<min_change) min_change= white;

        }
        return min_change;
    }
};