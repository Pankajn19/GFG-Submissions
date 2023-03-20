//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    int rec(int ind, int prev, int a[], int n,vector<vector<int>>& dp){
        if(ind==n) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int nt = rec(ind+1,prev,a,n,dp);
        int t = INT_MIN;
        if(prev==-1 || a[ind]>a[prev]) t = 1 + rec(ind+1,ind,a,n,dp);
        return dp[ind][prev+1] = max(t,nt);
    }
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return rec(0,-1,a,n,dp);
       // your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends