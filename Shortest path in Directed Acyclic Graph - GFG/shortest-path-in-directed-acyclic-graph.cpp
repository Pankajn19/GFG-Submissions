//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     void dfs(int node, vector<int>& vis, stack<int>& st,  vector<pair<int,int>> adj[]){
         vis[node] = 1;
         for(auto i : adj[node]){
             int x = i.first;
             if(!vis[x]) dfs(x,vis,st,adj);
         }
         st.push(node);
     }
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
         vector<pair<int,int>> adj[n];
         for(int i=0;i<m;i++) adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
         stack<int> st;
         vector<int> vis(n,0);
         for(int i=0;i<n;i++){
             if(!vis[i]) dfs(i,vis,st,adj);
         }
         vector<int> ans(n,1e9);
         ans[0] = 0;
         while(st.size()){
             int x = st.top();
             st.pop();
             for(auto i : adj[x]){
                 int y = i.first;
                 int z = i.second;
                 if(z+ans[x]<ans[y]) ans[y] = z + ans[x];
             }
         }
         for(int i=0;i<n;i++){
             if(ans[i]==1e9) ans[i]=-1;
         }
        
         return ans;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends