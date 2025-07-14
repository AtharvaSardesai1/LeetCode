class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowBegin=0, rowEnd=matrix.size()-1, colBegin=0, colEnd=matrix[0].size()-1;
        vector<int> ans;
        while(rowBegin<=rowEnd && colBegin<=colEnd){
            //Traverse Right
            for(int j=colBegin; j<=colEnd; j++){
                ans.push_back(matrix[rowBegin][j]);
            }
            rowBegin++;

            //Traverse Down
            for(int i=rowBegin; i<=rowEnd; i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;

            //Traverse Left
            if(rowBegin<=rowEnd){
                for(int j=colEnd; j>=colBegin; j--){
                    ans.push_back(matrix[rowEnd][j]);
                }
            }
            rowEnd--;
            
            //Traverse Up
            if(colBegin<=colEnd){
                for(int i=rowEnd; i>=rowBegin; i--){
                    ans.push_back(matrix[i][colBegin]);
                }
            }
            colBegin++;

            
        }
        return ans;
    }
};