//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int i, int j,string word ,vector<vector<char>>& board, int n, int m){
        vector<vector<int>> vis1(n, vector<int>(m,0));
        vis1[i][j] = 1;
        queue<pair<pair<int,int>, int>> q;
        q.push({{i,j},0});
        vector<vector<int>> mov = {{-1,0},{0,-1},{1,0},{0,1}};
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int ind = q.front().second;
            q.pop();
            if(ind==word.size()-1) return true;
            for(int k=0;k<4;k++){
                int nx = x + mov[k][0];
                int ny = y + mov[k][1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis1[nx][ny] && word[ind+1]==board[nx][ny]){
                    vis1[nx][ny] = 1;
                    q.push({{nx,ny},ind+1});
                }
            }
           
        }
         return false;
        
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0] && bfs(i,j,word,board, n, m)) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends