class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>&vis){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(it,adj,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& is) {
        int n = is.size();
        vector<int> vis(n,0);
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(is[i][j] && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adj,vis);
            }
        }

       return cnt;

        
    }
};