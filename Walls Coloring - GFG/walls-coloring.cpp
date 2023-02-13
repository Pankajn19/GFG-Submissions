//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &c, int n) {
        vector<int> p(n);
        vector<int> b(n);
        vector<int> y(n);
        p[0] = c[0][0];
        b[0] = c[0][1];
        y[0] = c[0][2];
        for(int i=1;i<n;i++){
            p[i] = c[i][0] + min(b[i-1], y[i-1]);
            b[i] = c[i][1] + min(p[i-1], y[i-1]);
            y[i] = c[i][2] + min(b[i-1], p[i-1]);
        }
        return min(p[n-1], min(b[n-1],y[n-1]));
        
        // Write your code here.
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends