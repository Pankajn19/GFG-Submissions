//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> reverseSpiral(int n, int m, vector<vector<int>>&a)  {
        int cnt = 0, minR = 0, minC = 0, maxR = n, maxC = m;
        int k = n*m;
        vector<int> ans;
 	      while(cnt<k){
 	          for(int i=minC;i<maxC;i++){
 	              ans.push_back(a[minR][i]);
 	              cnt++;
 	              if(k==cnt) break;
 	          }
 	          minR++;
 	          if(k==cnt) break;
 	          for(int i=minR;i<maxR;i++){
 	              ans.push_back(a[i][maxC-1]);
 	              cnt++;
 	              if(k==cnt) break;
 	          }
 	          if(k==cnt) break;
 	          maxC--;
 	          for(int i=maxC-1;i>=minC;i--){
 	              ans.push_back(a[maxR-1][i]);
 	              cnt++;
 	              if(k==cnt) break;
 	          }
 	          if(k==cnt) break;
 	          maxR--;
 	          for(int i=maxR-1;i>=minR;i--){
 	              ans.push_back(a[i][minC]);
 	              cnt++;
 	              if(k==cnt) break;
 	          }
 	          if(k==cnt) break;
 	          minC++;
 	      }
 	      reverse(ans.begin(), ans.end());
 	      return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin>>R>>C;
        vector<vector<int>> a(R, vector<int>(C, 0));
        for(int i = 0;i < R*C;i++)
            cin>>a[i/C][i%C];
        Solution ob;
        vector<int>ans=ob.reverseSpiral(R,C,a);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
            cout<<endl;
    }
    return 0;
}

// } Driver Code Ends