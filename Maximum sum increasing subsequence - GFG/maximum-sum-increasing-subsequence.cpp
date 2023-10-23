//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	int rec(int ind, int last, int arr[], int n, vector<vector<int>>& dp){
	    if(!ind){
	        if(last==n || arr[ind]<arr[last]) return arr[ind];
	        return 0;
	    }
	    
	    if(dp[ind][last]!=-1) return dp[ind][last];
	    int tk = 0;
	    if(last==n || arr[ind]<arr[last]) tk = arr[ind] + rec(ind-1,ind,arr,n,dp);
	    int ntk = rec(ind-1,last,arr,n,dp);
	    return dp[ind][last] = max(tk,ntk);
	}
	int maxSumIS(int arr[], int n)  
	{  vector<vector<int>> dp(n, vector<int>(n+1,0));
	   for(int i=1;i<n;i++){
	       if(arr[i]>arr[0]) dp[0][i] = arr[0];
	   }
	   dp[0][n] = arr[0];
	   for(int i=1;i<n;i++){
	       for(int j=i+1;j<=n;j++){
	           int tk = 0;
	           if(j==n || arr[j]>arr[i]) tk = arr[i] + dp[i-1][i];
	           int ntk = dp[i-1][j];
	           dp[i][j] = max(tk,ntk);
	       }
	   }
	
	   return dp[n-1][n];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends