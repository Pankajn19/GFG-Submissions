//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
  public:
    int rec(int ind, vector<int>& cost, int n, vector<int>& dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int tk1 = cost[ind] + rec(ind+1,cost,n,dp);
        int tk2 = cost[ind] + rec(ind+2,cost,n,dp);
        return dp[ind] = min(tk1,tk2);
    }
    int minCostClimbingStairs(vector<int>&cost ,int n) {
        vector<int> dp1(n,-1), dp2(n,-1);
        int ans1 = rec(0,cost,n,dp1);
        int ans = rec(1,cost,n,dp2);
        return min(ans1,ans);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends