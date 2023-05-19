//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int rec(int ind, int val[], int wt[], int w, int n,vector<vector<int>>& dp){
        if(ind==0) return val[0] * (w/wt[0]);
        if(dp[ind][w]!=-1) return dp[ind][w];
        int tk = 0;
        if(wt[ind]<=w) tk =  val[ind] + rec(ind,val,wt,w-wt[ind],n,dp);
        int ntk = rec(ind-1,val,wt,w,n,dp);
        return dp[ind][w] = max(tk,ntk);
    }
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
        return rec(n-1,val,wt,w,n,dp);
       
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends