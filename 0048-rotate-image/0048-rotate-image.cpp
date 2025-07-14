class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<(n+1)/2; i++){
            for(int j=0; j<n/2; j++){
                //Store the bottom left
                int temp = matrix[n-1-j][i];

                //Replace bottom left with bottom right
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];

                //Replace bottom right with top right
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];

                //Replace top right with top left
                matrix[j][n-1-i] = matrix[i][j];

                //Replace top right with temp
                matrix[i][j] = temp;
            }
        }
    }
};