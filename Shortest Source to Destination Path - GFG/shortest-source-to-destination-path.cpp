//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> a, int x, int y) {
        vector<vector<int>> vis(n,vector<int>(m,0));
        if(!a[0][0]) return -1;
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        vis[0][0] = 1;
        vector<vector<int>> mov = {{0,1},{0,-1},{1,0},{-1,0}};
        while(q.size()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int dist = q.front().second;
            q.pop();
            if(r==x && y==c) return dist;
            for(int i=0;i<4;i++){
                int nr = r+mov[i][0];
                int nc = c + mov[i][1];
                if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && a[nr][nc]){
                    q.push({{nr,nc},dist+1});
                    vis[nr][nc] = 1;
                }
            }
            
        }
        return -1;
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends