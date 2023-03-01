//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    bool rec(vector<int>& arr, int i, int sum,vector<vector<int>>&dp){
        if(!sum) return true;
        if(i==0) return arr[i]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool nt = rec(arr,i-1,sum,dp);
        bool t = false;
        if(sum>=arr[i]) t = rec(arr,i-1,sum-arr[i],dp);
        return dp[i][sum] = nt || t;
    }
    bool isSubsetSum(vector<int>arr, int sum){
        vector<vector<int>> dp(arr.size()+1,vector<int>(sum+1,-1)); 
        return rec(arr,arr.size()-1,sum,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends