//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int n, int k, vector<char> &tasks) {
        vector<int> freq(26,0);
        for(int i=0;i<n;i++) freq[tasks[i]-'A']++;
        sort(freq.begin(), freq.end());
        int maxf = freq[25] - 1;
        int ans = (maxf)*k;
        for(int i=24;i>=0;i--) ans-=min(maxf,freq[i]);
        if(ans<0) return n;
        return ans+n;
        
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends