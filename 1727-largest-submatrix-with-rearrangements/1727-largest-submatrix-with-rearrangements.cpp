class Solution {
public:
   
    // return psm[6];
    
    int largestSubmatrix(vector<vector<int>>& matrix) {
      int n = matrix.size();
      int m = matrix[0].size();
      vector<vector<int>> ans(n,vector<int>(m,0));
     for(int i=0;i<m;i++){
        int k = 0;
        while(k<n){
        while(k<n && !matrix[k][i]) k++;
        if(k<n) ans[k][i] = 1;
        int l = k+1;
        while(l<n && matrix[l][i]){
          ans[l][i] = ans[l-1][i] + 1;
          l++;
        }
        k=l+1;
        }
      }
      
      int answer = 0;
      for(int i=0;i<n;i++){
        sort(ans[i].begin(), ans[i].end(), greater<int>());
       // reverse(cur.begin(), cur.end());
        for(int j=0;j<m;j++) answer= max( answer, (ans[i][j]*(j+1)));
      }
  /*    if(n==3 && m==3 ){
        return ans[2][2];

      }
      */
      
     // return ans[0][0];
      return answer;      
    }
};