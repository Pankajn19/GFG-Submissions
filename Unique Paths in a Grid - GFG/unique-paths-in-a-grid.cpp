//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        vector<vector<int>> ans(n,vector<int>(m));
        int mod = 1e9 + 7;
        if( !grid[n-1][m-1]) return 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!grid[i][j]) ans[i][j] = 0;
                else if(!i && !j) ans[i][j] = 1;
                else if(!i) ans[i][j] = ans[i][j-1]%mod;
                else if(!j )  ans[i][j] = ans[i-1][j]%mod;
                else ans[i][j] = (ans[i-1][j]%mod + ans[i][j-1]%mod)%mod;
            }
        }
        return ans[n-1][m-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m,x;
        cin>>n>>m;
        
        vector<vector<int>> grid(n,vector<int>(m));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin>>grid[i][j];
            }
        }

        Solution ob;
        cout << ob.uniquePaths(n,m,grid) << endl;
    }
    return 0;
}
// } Driver Code Ends