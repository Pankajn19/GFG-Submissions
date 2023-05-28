//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> d, string p) {
        vector<string> ans;
        for(int i=0;i<d.size();i++){
            int j = 0, k = 0;
            while(j<d[i].size() && k<p.size()){
                if(d[i][j]>=97 && d[i][j]<=122) j++;
                else if(d[i][j]!=p[k]) break;
                else if(d[i][j]==p[k]){
                    k++;
                    j++;
                }
            }
            if(k==p.size()) ans.push_back(d[i]);
        }
        sort(ans.begin(), ans.end());
        if(ans.empty()) return {"-1"};
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends