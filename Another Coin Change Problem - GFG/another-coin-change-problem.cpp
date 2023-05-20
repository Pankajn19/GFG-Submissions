//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public: 
    int rec(int ind,int n, int k, int t, vector<int>& coins,vector<vector<vector<int>>>& dp){
        if(ind==0){
            if(k==0) return true;
            if(t%coins[0]==0 && t/coins[0]==k) return true;
            return false;
        }
        if(k==0) return t==0;
        if(t==0) return k==0;
        if(dp[ind][k][t]!=-1) return dp[ind][k][t];
        int tk = 0;
        if(coins[ind]<=t) tk = rec(ind,n,k-1,t-coins[ind],coins,dp);
        int ntk = rec(ind-1,n,k,t,coins,dp);
        return dp[ind][k][t] = tk || ntk;
    }
    bool makeChanges(int N, int K, int target, vector<int> &coins) {
        vector<vector<vector<int>>> dp(N,vector<vector<int>>(K+1,vector<int>(target+1,-1)));
        return rec(N-1,N,K,target,coins,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends