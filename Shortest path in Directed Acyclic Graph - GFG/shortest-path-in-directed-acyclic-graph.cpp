//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
         vector<pair<int,int>> adj[n];
         for(int i=0;i<m;i++) adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
         priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
         vector<int> ans(n,INT_MAX);
         ans[0] = 0;
         pq.push({0,0});
         while(pq.size()){
             int x = pq.top().second;
             int dist = pq.top().first;
             pq.pop();
             for(auto i : adj[x]){
                 if(dist+i.second<ans[i.first]){
                     ans[i.first] = dist+i.second;
                     pq.push({dist+i.second,i.first});
                 }
             }
         }
       for(int i=1;i<n;i++){
           if(ans[i]==INT_MAX) ans[i] = -1;
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