//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int rec(int i, int coins[], int sum, vector<vector<long long int>>& dp){
        if(!sum) return 1;
        if(!i){
            if(sum%coins[i]) return 0;
            return 1;
        }
        if(dp[i][sum]!=-1) return dp[i][sum];
        long long int tk = 0;
        if(coins[i]<=sum) tk = rec(i,coins,sum-coins[i],dp);
        long long int ntk = rec(i-1,coins,sum,dp);
        return dp[i][sum] = tk + ntk;
    }
    long long int count(int coins[], int n, int sum) {
        sort(coins, coins+n);
        vector<vector<long long int>> dp(n, vector<long long int>(sum+1,-1));
        return rec(n-1,coins,sum,dp);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends