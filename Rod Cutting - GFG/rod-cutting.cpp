//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int rec(int len, int price[],vector<int>& dp){
        if(len==1) return price[0];
        if(len==0) return 0;
        if(dp[len-1]!=-1) return dp[len-1];
         int maxi = 0;
        for(int i=1;i<len;i++){
            int temp =  max(price[len-1],max(price[i-1]+price[len-i-1], price[i-1]+rec(len-i,price,dp)));
            maxi = max(maxi,temp);
        }
        return dp[len-1] = maxi;
    }
    int cutRod(int price[], int n) {
        vector<int> dp(n,-1);
        return rec(n,price,dp);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends