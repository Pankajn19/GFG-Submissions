//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long maximumProfit(vector<long long>&prices, int n) {
        long long prev1,prev2,cur1,cur2;
        prev1 = prices[n-1];
        prev2 = 0;
        for(int i=n-2;i>=0;i--){
           cur1 = (long long)max(prev1,prices[i]+prev2);
           cur2 = (long long)max(-prices[i]+prev1,prev2);
           prev1 = cur1;
           prev2 = cur2;
        }
        return prev2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<long long> prices;
        
        for(int i=0; i<n; ++i){
            long long x; cin>>x;
            prices.push_back(x);
        }
        
        Solution obj;
        cout<<obj.maximumProfit(prices, n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends