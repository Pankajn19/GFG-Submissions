//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int rec(int ind, int w, int wt[], int val[], int n, vector<vector<int>>& dp){
        if(ind==n) return 0;
        if(dp[ind][w]!=-1) return dp[ind][w];
        int ntk = rec(ind+1,w,wt,val,n,dp);
        int tk = 0;
        if(wt[ind]<=w) tk = val[ind] + rec(ind+1,w-wt[ind],wt,val,n,dp);
        return dp[ind][w] = max(tk,ntk);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(w+1,-1));
        return rec(0,w,wt,val,n,dp);
        
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