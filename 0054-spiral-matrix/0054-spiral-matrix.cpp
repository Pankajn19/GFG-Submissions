class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
        int startRow=0,endRow=matrix.size()-1;
        int startCol=0,endCol=matrix[0].size()-1;
        while(startRow<=endRow && startCol<=endCol){
            //Traverse Right
            for(int c=startCol;c<=endCol;c++){
                res.push_back(matrix[startRow][c]);
            }
            startRow++;
            //Traverse Down
            for(int r=startRow;r<=endRow;r++){
                res.push_back(matrix[r][endCol]);
            }
            endCol--;
            if(startRow<=endRow){
                //Traverse Left
                for(int c=endCol;c>=startCol;c--){
                    res.push_back(matrix[endRow][c]);
                }
            }
            endRow--;

            if(startCol<=endCol){
                //Traverse Up
                for(int r=endRow;r>=startRow;r--){
                    res.push_back(matrix[r][startCol]);
                }
            }
            startCol++;
        }
        return res;
    }
};