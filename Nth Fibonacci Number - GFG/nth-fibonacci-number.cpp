//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int mod = 1e9+7;
    int nthFibonacci(int n){
        vector<long long int> fib(n+1);
        fib[0] = 0;
        fib[1] = 1;
        for(int i=2;i<=n;i++) fib[i] = (fib[i-1] + fib[i-2])%mod;
        return fib[n];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends