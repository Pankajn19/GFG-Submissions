//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int N, int S){
        if(!S && N>1) return "-1";
        string ans;
        while(S){
            if(S>=9){
                ans+='9';
                N--;
                S-=9;
            }
            else{
                ans+='0'+S;
                N--;
                S=0;
            }
            
        }
        if(N<0) return "-1";
        while(N--) ans+='0';
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends