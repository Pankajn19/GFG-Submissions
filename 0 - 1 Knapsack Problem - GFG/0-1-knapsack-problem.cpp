//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int rec(int ind, int wt[], int val[], int n, int w, vector<vector<int>>& dp){
        if(ind==0){
            if(wt[0]<=w) return val[0];
            return 0;
        }
        if(dp[ind][w]!=-1) return dp[ind][w];
        int tk = 0;
        if(wt[ind]<=w) tk = val[ind] + rec(ind-1,wt,val,n,w-wt[ind],dp);
        int ntk  = rec(ind-1,wt,val,n,w,dp);
        return dp[ind][w] = max(tk,ntk);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int> (W+1,-1));
       return rec(n-1,wt,val,n,W,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends