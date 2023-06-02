//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int n1,int n2,int n3,vector<int> &s1,vector<int> &s2,vector<int> &s3){
        vector<int> suf1(n1,s1[n1-1]), suf2(n2,s2[n2-1]), suf3(n3,s3[n3-1]);
        for(int i=n1-2;i>=0;i--) suf1[i] = suf1[i+1] + s1[i];
        for(int i=n2-2;i>=0;i--) suf2[i] = suf2[i+1] + s2[i];
        for(int i=n3-2;i>=0;i--) suf3[i] = suf3[i+1] + s3[i];
        unordered_set<int> st1(suf1.begin(), suf1.end()), st2;
        for(int i=0;i<n2;i++){
            if(st1.find(suf2[i])!=st1.end()) st2.insert(suf2[i]);
        } 
        for(int i=0;i<n3;i++){
            if(st2.find(suf3[i])!=st2.end()) return suf3[i];
        }
        return 0;
        
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}
// } Driver Code Ends