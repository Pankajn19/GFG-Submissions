//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod = 1e9 + 7;
class Solution{

	public:
	int perfectSum(int arr[], int n, int sum)
{
        vector<vector<int>> dp(n,vector<int>(sum+1,0));
        if(!arr[0]) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0] && arr[0]<=sum) dp[0][arr[0]] = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                int ntk = dp[i-1][j];
                int tk = 0;
                if(arr[i]<=j) tk = dp[i-1][j-arr[i]];
                dp[i][j] = (tk%mod + ntk%mod)%mod;
            }
        }
        return dp[n-1][sum]%mod;
        
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