//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> mov = {{-1,0},{0,-1},{1,0},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!matrix[i][j]) continue;
                int cnt = 0;
                for(int k=0;k<8;k++){
                    int x = i + mov[k][0];
                    int y = j + mov[k][1];
                    if(x>=0 && x<n && y>=0 && y<m && !matrix[x][y]) cnt++;
                }
                ans+=(cnt>0 && cnt%2==0);
            }
        }
        return ans;
        // Code here
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends