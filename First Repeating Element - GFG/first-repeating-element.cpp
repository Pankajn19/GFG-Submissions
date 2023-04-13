//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        unordered_map<int,int> mp;
        mp[arr[0]] = 0;
        int ans = INT_MAX;
        for(int i=1;i<n;i++){
            if(mp.find(arr[i])!=mp.end()) ans = min(ans,mp[arr[i]]);
            else mp[arr[i]] = i;
        }
        if(ans==INT_MAX) return -1;
        return ++ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}

// } Driver Code Ends