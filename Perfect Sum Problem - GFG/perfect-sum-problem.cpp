//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int rec(int ind, int arr[], int n, int sum, vector<vector<int>>& dp){
	    if(ind==-1){
	        if(!sum) return 1;
	        return 0;
	    }
	    if(dp[ind][sum]!=-1) return dp[ind][sum];
	    if(arr[ind]<=sum) return dp[ind][sum]  = (rec(ind-1,arr,n,sum-arr[ind],dp)%mod + rec(ind-1,arr,n,sum,dp)%mod)%mod;
	    return dp[ind][sum] = rec(ind-1,arr,n,sum,dp)%mod;
	}
	int perfectSum(int arr[], int n, int sum)
	{
	    vector<vector<int>> dp(n, vector<int>(sum+1,-1));
        return rec(n-1,arr,n,sum,dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends