//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                for(int j=i;j<=min(n-1,i+x);j++) ans[j] = 1;
                for(int j=i;j>=max(0,i-x);j--) ans[j] = 1;
            }
        }
        for(int i=0;i<n;i++){
            if(ans[i]==0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends