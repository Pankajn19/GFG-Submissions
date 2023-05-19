class Solution {
public:
    int rec(int ind, vector<int>& c, int amt, vector<vector<int>>& dp){
      if(ind==0){
        if(amt%c[0]==0) return amt/c[0];
        return 1e9;
      }
      if(dp[ind][amt]!=-1) return dp[ind][amt];
      int tk = 1e9;
      if(c[ind]<=amt) tk = 1 + rec(ind,c,amt-c[ind],dp);
      int ntk = rec(ind-1,c,amt,dp);
      return dp[ind][amt] = min(tk,ntk);
    }
    int coinChange(vector<int>& c, int amt) {
      int n = c.size(); 
      vector<vector<int>> dp(n , vector<int>(amt+1,0));
      for(int i=0;i<=amt;i++){
          if(i%c[0]==0) dp[0][i]  = i/c[0];
          else dp[0][i] = 1e9;
      }  
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                int tk = 1e9;
                if(c[i]<=j) tk = 1 + dp[i][j-c[i]];
                int ntk = dp[i-1][j];
                dp[i][j] = min(tk,ntk);
                
            }
        }
        if (dp[n-1][amt]>=1e9) return -1;
        return dp[n-1][amt];
      

         
    }
};