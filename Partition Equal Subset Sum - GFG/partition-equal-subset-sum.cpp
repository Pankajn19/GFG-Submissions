//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
          int sum = accumulate(arr, arr+n,0);
        if(sum%2) return 0;
        if(n==1) return 0;
        if(n==2 && arr[0]!=arr[1]) return 0;
        sum/=2;
          vector<vector<int>> dp(n,vector<int>(sum+1,0)); 
         for(int i=0;i<n;i++) dp[i][0] = 1;
         dp[0][arr[0]] = 1;
         for(int i=1;i<n;i++){
             for(int j=1;j<=sum;j++){
                  int nt = dp[i-1][j];
                  int t = 0;
                  if(j>=arr[i]) t = dp[i-1][j-arr[i]];
                  dp[i][j] = nt || t;
                 
             }
         }
         return dp[n-1][sum];
        // code here
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends