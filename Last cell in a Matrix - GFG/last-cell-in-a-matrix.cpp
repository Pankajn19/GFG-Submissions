//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        vector<pair<int,int>> mov = {{0,1}, {1,0},{0,-1},{-1,0}};
        int i=0,j=0,k=0;
          pair<int,int> last;
        int m = matrix.size(), n = matrix[0].size();
        while(i>=0 && i<m && j>=0 && j<n){
            last = {i,j};
            if(matrix[i][j]==1){
                matrix[i][j] = 0;
                k = (k+1)%4;
            }
            i+=mov[k].first;
            j+=mov[k].second;
        }
        //code here
        return last;
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends