//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> g) {
        if(n<=k) return g[n-1];
        long long sum = accumulate(g.begin(), g.end(), 0);
        g.resize(n);
        int x = n-k;
        int i = 0;
        int j = k;
        while(x--){
            g[j] = sum;
            sum-=g[i];
            sum+=g[j];
            i++;
            j++;
        }
        return g[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends