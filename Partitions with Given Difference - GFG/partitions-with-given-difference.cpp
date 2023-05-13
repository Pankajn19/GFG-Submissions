//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

int mod = 1e9 + 7;
class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
         int t  = accumulate(arr.begin(), arr.end(), 0);
         if(t-d<0 || (t-d)%2) return 0;
        int sum = (t-d)/2;
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
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends