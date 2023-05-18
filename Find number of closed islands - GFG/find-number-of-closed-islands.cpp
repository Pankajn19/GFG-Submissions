//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    void bfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,int m, int n ){
        vis[row][col] = 1;
        queue<pair<int,int>> q;
        q.push({row,col});
        while(!q.empty()){
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            vector<vector<int>> mov = {{1,0},{0,1},{-1,0},{0,-1}};
            for(int k=0;k<4;k++){
                int nrow = i+mov[k][0];
                int ncol = j+mov[k][1];
                if(nrow>=0 && ncol>=0 && nrow<n && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }

        }
    }
    int closedIslands(vector<vector<int>>& grid, int n, int m) {
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(grid[i][0] && !vis[i][0]) bfs(i,0,grid,vis,m,n);
            if(grid[i][m-1] && !vis[i][m-1]) bfs(i,m-1,grid,vis,m,n);
        }
        for(int i=0;i<m;i++){
             if(grid[0][i] && !vis[0][i]) bfs(0,i,grid,vis,m,n);
             if(grid[n-1][i] && !vis[n-1][i]) bfs(n-1,i,grid,vis,m,n);
            
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] && vis[i][j]==0){
                    ans++;
                    bfs(i,j,grid,vis,m,n);
                }
            }
        
        }
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends