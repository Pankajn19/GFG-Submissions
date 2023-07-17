//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s, string t, int n, int m)
    {
         vector<vector<int>> dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i && !j){
                    if(s[i]==t[j]) dp[i][j] = 1;
                }
                else if(!i){
                    if(s[i]==t[j]) dp[i][j] =1;
                    else dp[i][j] = dp[i][j-1];
                }
                else if(!j){
                    if(s[i]==t[j]) dp[i][j] = 1;
                    else dp[i][j] = dp[i-1][j];
                }
                else{
                    if(s[i]==t[j]) dp[i][j] = 1+dp[i-1][j-1];
                    else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return m+n - dp[n-1][m-1];
        
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends