//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n,int k,vector<int> &a){
        vector<int> left(n,a[0]);
        vector<int> right(n,a[n-1]);
        for(int i=1;i<n;i++) left[i] = max(a[i],left[i-1]);
        for(int i=n-2;i>=0;i--) right[i] = min(a[i],right[i+1]);
        int ans = 0;
        for(int i=0;i<n-1;i++){
            if(left[i]+right[i+1]>=k) ans++;
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends