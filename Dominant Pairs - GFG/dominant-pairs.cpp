//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        sort(arr.begin(), arr.begin()+n/2);
        for(int i=n/2;i<n;i++) arr[i]*=5;
        int ans = 0;
        for(int i=n/2;i<n;i++){
            int j = 0, k = n/2 - 1;
            while(j<=k){
                int mid = (j+k)/2;
                if(arr[mid]>=arr[i]){
                    ans+=k-mid+1;
                    k=mid-1;
                }
                else j=mid+1;
            }
        }
        return ans;
    }  
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.dominantPairs(n,arr)<<endl;
    }
}
// } Driver Code Ends