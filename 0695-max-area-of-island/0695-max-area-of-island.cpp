class Solution {
public:
    int bfs(int i, int j,vector<vector<int>>& grid,vector<vector<int>>& vis){
      int ans = 0;
      int n = grid.size();
      int m = grid[0].size(); 
      vis[i][j] = 1;
      queue<pair<int,int>> q;
      q.push({i,j});
      vector<vector<int>> mov = {{0,-1},{-1,0},{1,0},{0,1}};
      while(q.size()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        ans++;
        for(int k=0;k<4;k++){
          int nr = x + mov[k][0];
          int nc = y + mov[k][1];
          if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]){
            vis[nr][nc] = 1;
            q.push({nr,nc});
          }
         }


      }
      return ans;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
      int n = grid.size();
      int ans = 0;
      int m = grid[0].size();
      vector<vector<int>> vis(n, vector<int>(m,0));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          if(!vis[i][j] && grid[i][j]) ans= max(ans, bfs(i,j,grid,vis));
        }
      }
      return ans;
        
    }
};