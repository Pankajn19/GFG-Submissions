//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int editDistance(string word1, string word2) {
        int n = word1.size();
    int m = word2.size();
    vector<int> prev(m+1,0), cur(m+1,0);
    for(int i=0;i<=m;i++) prev[i] = i;    
    for(int i=1;i<=n;i++){
      cur[0] = i;
      for(int j=1;j<=m;j++){
        if(word1[i-1]==word2[j-1]) cur[j] = prev[j-1];
        else cur[j] = 1 + min(cur[j-1], min(prev[j-1], prev[j]));
      }
      prev = cur;
    }
    return  prev[m];
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends