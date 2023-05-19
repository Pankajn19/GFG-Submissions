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
      vector<int> prev(amt+1,0), cur(amt+1,0);
      for(int i=0;i<=amt;i++){
          if(i%c[0]==0) prev[i]  = i/c[0];
          else prev[i] = 1e9;
      }  
        for(int i=1;i<n;i++){
            for(int j=0;j<=amt;j++){
                int tk = 1e9;
                if(c[i]<=j) tk = 1 + cur[j-c[i]];
                int ntk = prev[j];
                cur[j] = min(tk,ntk);
                
            }
            prev = cur;
        }
        if (prev[amt]>=1e9) return -1;
        return prev[amt];
      

         
    }
};