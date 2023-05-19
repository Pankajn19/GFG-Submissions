class Solution {
public:
    int change(int amt, vector<int>& c) {
      int n = c.size();
      vector<vector<int>> dp(n,vector<int>(amt+1,0));
      for(int i=0;i<=amt;i++){
        if(i%c[0]==0) dp[0][i] = 1;
      }
      for(int i=1;i<n;i++){
        for(int j=0;j<=amt;j++){
          int ntk = dp[i-1][j];
          int tk = 0;
          if(c[i]<=j) tk =  dp[i][j-c[i]];      
          dp[i][j] = tk + ntk;

        }
      }
      return dp[n-1][amt];

     // return rec(n-1,c,amt,dp);
        
    }
};