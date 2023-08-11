//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {
        sort(coins, coins+n);
        vector<long long int> prev(sum+1,0), cur(sum+1,0);
      //  prev[0] = 1;
        for(int i=0;i<=sum;i++){
            if(i%coins[0]==0) prev[i] = 1;
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<=sum;j++){
                long long int tk = 0;
                if(coins[i]<=j) tk = cur[j-coins[i]];
                long long int ntk = prev[j];
                 cur[j] = tk + ntk;
            }
            prev = cur;
        }
        return prev[sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends