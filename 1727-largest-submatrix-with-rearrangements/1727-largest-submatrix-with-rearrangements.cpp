class Solution {
public:
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
     for(int i=0;i<m;i++){
        int k = 0;
        while(k<n){
        while(k<n && !matrix[k][i]) k++;
        if(k<n) matrix[k][i] = 1;
        int l = k+1;
        while(l<n && matrix[l][i]){
          matrix[l][i] = matrix[l-1][i] + 1;
          l++;
        }
        k=l+1;
        }
      }
      
      int answer = 0;
      for(int i=0;i<n;i++){
        sort(matrix[i].begin(), matrix[i].end(), greater<int>());
        for(int j=0;j<m;j++) answer= max( answer, (matrix[i][j]*(j+1)));
      }
      return answer;      
    }
};