class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& d) {
      vector<int> adj[n+1];
      for(int i=0;i<d.size();i++){
        adj[d[i][0]].push_back(d[i][1]);
        adj[d[i][1]].push_back(d[i][0]);
      }
      vector<int> clr(n+1,-1);
      queue<pair<int,int>> q;
      for(int i=1;i<=n;i++){
        if(clr[i]==-1){
          clr[i] = 0;
         q.push({i,0});
         while(q.size()){
         int x = q.front().first;
         int color = q.front().second;
         q.pop();
         for(int j=0;j<adj[x].size();j++){
           int nr = adj[x][j];
           if(clr[nr]==-1){
             clr[nr] = 1-color;
             q.push({nr,1-color});
           }
           else if(clr[nr]==color) return false;
         }
     
      }
        
      }
        
      }
      return true;
        
    }
};