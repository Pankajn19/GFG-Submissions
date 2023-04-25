//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int m, int n, vector<int>& f){
      
        int ans = 0;
        if(m==0) return true;
        if(m>n) return false;
        if(n==1) return f[0]==0;
        if(n==2) {
            if(m==2) return false;
            if(f[0]==1 || f[1]==1) return false;
            return true;
        }
        if(f[0]==0 && f[1]==0){
            f[0]= 1;
            ans++;
        }
        if(f[n-2]==0 && f[n-1]==0){
            f[n-1] = 1;
            ans++;
        }
        for(int i=1;i<n-1;i++){
            if(f[i]==0){
                if(f[i-1]==0 && f[i+1]==0){
                        f[i] = 1;
                        ans++;
                    }
            }
                
            } 
        if(ans>=m) return true;
        return false;
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<int> seats(m);
        for (int i = 0; i < m; i++) {
            cin >> seats[i];
        }
        Solution obj;
        if (obj.is_possible_to_get_seats(n, m, seats)) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
}

// } Driver Code Ends