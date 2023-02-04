//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int n, vector<vector<int>> matrix)
    {
        vector<vector<int>> dp(n,vector<int>(n));
        for(int i=0;i<n;i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
               // if(!i) dp[i][j] = matrix[i][j];
                 if(j==0) dp[i][j] = matrix[i][j] + max(dp[i-1][j+1],dp[i-1][j]);
                else if(j==n-1) dp[i][j] = matrix[i][j] + max(dp[i-1][j-1],dp[i-1][j]);
                else dp[i][j] = matrix[i][j] + max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]));
            }
        }
        int mini = INT_MIN;
        
            for(int j=0;j<n;j++){
                mini = max(mini,dp[n-1][j]);
            }
        return mini;
        
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
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends