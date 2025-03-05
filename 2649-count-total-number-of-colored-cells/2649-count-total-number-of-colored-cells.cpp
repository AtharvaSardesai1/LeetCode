class Solution {
public:
    long long coloredCells(int n) {
        long long sum = 0;
        if (n==1) return 1;

        for (int i=1; i<n; i++){
            sum += 4*i;
        }
        return sum +1;
    }
};