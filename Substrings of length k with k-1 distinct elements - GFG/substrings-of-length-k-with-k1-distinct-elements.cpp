//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        unordered_map<char,int> mp;
        for(int i=0;i<k;i++) mp[s[i]]++;
        int ans = 0;
        if(mp.size()==k-1) ans++;
        int i=0,j=k;
        while(j<s.size()){
            if(mp[s[i]]==1) mp.erase(s[i]);
            else mp[s[i]]--;
            mp[s[j]]++;
            if(mp.size()==k-1) ans++;
            i++;
            j++;
        }
        return ans;
        // code here
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends