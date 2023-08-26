//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int i = 0, j =0, n = s.size(), ans=-1;
        unordered_map<char, int> mp;
        while(i<n){
            mp[s[i]]++;
            while(mp.size()>k){
                if(mp[s[j]]==1) mp.erase(s[j]);
                else mp[s[j]]--;
                j++;
            }
            if(mp.size()==k) ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends