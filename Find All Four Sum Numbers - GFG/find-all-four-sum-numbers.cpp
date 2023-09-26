//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &nums, int t) {
        
          int n = nums.size();
      vector<vector<int>> ans;
      sort(nums.begin(), nums.end());
      for(int i=0;i<n-3;i++){
        long long a = nums[i];
        for(int j=i+1;j<n-2;j++){
          long long z = nums[j];
          int k = j+1, l = n-1;         
          while(k<l){
            long long x = nums[k], y = nums[l];
            if((x+y+z+a)==t){
              ans.push_back({nums[i],nums[j],nums[k],nums[l]});
              while(k<l && nums[k]==x) k++;
              while(k<l && nums[l]==y) l--;
            }
            else if(a+x+y+z<t) k++;
            else l--;
          }
          while(j<n-2 && nums[j]==z) j++;
          j--;
        }
        while(i<n-3 && nums[i]==a)  i++;
        i--;
      }
      return ans;
        
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