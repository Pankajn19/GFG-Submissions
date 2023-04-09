//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> v, int n) {
        int ans = 0;
    int count = 0;
    vector<pair<int, char> > data;
    for (int i = 0; i < v.size(); i++) {
        data.push_back({ v[i][0], 'x' });
        data.push_back({ v[i][1], 'y' });
    }
    sort(data.begin(), data.end());
    for (int i = 0; i < data.size(); i++) {
        if (data[i].second == 'x')
            count++;
        if (data[i].second == 'y')
            count--;
        ans = max(ans, count);
    }
    return ans; 
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends