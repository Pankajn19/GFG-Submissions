class Solution {
public:
    long long rec(int ind, vector<vector<int>>& q, int n,vector<long long>& dp){
      if(ind>=n) return 0;
      if(dp[ind]!=-1) return dp[ind];
      long long skip = rec(ind+1,q,n,dp);
      long long solve = q[ind][0] + rec(ind+q[ind][1]+1,q,n,dp);
      return dp[ind] = max(skip,solve);
    }
    long long mostPoints(vector<vector<int>>& q) {
      int n  = q.size();
      vector<long long> dp(n,-1);
      return rec(0,q,n,dp);
        
    }
};