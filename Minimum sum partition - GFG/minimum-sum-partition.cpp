//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

  public:
   bool issum(int arr [], int sum, int n){
        vector<vector<bool>> dp(n,vector<bool>(sum+1,0)); 
         for(int i=0;i<n;i++) dp[i][0] = true;
         dp[0][arr[0]] = 1;
         for(int i=1;i<n;i++){
             for(int j=1;j<=sum;j++){
                  bool nt = dp[i-1][j];
                  bool t = false;
                  if(j>=arr[i]) t = dp[i-1][j-arr[i]];
                  dp[i][j] = nt || t;
                 
             }
         }
         return dp[n-1][sum];
        
    }
	int minDifference(int arr[], int n)  { 
	    int sum = accumulate(arr,arr+n,0);
	    int ans = INT_MAX;
	    for(int i=sum/2;i>=0;i--){
	        if(issum(arr,i,n)) return abs(sum-2*i);
	    }
	    return sum;
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
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends