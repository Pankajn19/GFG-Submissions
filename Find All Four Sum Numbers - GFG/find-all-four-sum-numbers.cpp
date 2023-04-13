//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                int v = j+1,l=n-1;
                int x = k- (arr[i]+arr[j]);
                vector<int> cur;
                while(v<l){
                    if(arr[v]+arr[l]==x){
                        cur.push_back(arr[i]);
                        cur.push_back(arr[j]);
                        cur.push_back(arr[v]);
                        cur.push_back(arr[l]);
                        ans.push_back(cur);
                        cur.clear();
                        v++;
                    }   
                    else if(arr[v]+arr[l]<x) v++;
                    else l--;
                }
            }
        }
        if(!ans.size()) return ans;
        sort(ans.begin(),ans.end());
        vector<vector<int>> f;
        for(int i=0;i<ans.size()-1;i++){
            if(ans[i]!=ans[i+1]) f.push_back(ans[i]); 
        }
        
        f.push_back(ans[ans.size()-1]);
        return f;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends