//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
       vector<int> row(n,0), col(n,0);
       for(int i=0;i<n;i++){
           int sum = 0;
           for(int j=0;j<n;j++) sum+=matrix[i][j];
           row[i] = sum;
       }
       for(int i=0;i<n;i++){
           int sum = 0;
           for(int j=0;j<n;j++) sum+=matrix[j][i];
           col[i] = sum;
       }
       vector<vector<int>> inc(n, vector<int>(n,0));
       int maxi = row[0];
       for(int i=0;i<n;i++) maxi = max({maxi, row[i], col[i]});
       int ans = 0;
       for(int i=0;i<n;i++) ans+=(maxi-row[i]);
       return ans;
       
       
        
    } 
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends