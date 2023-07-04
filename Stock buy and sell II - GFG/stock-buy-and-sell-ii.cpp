//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int rec(int ind, vector<int>& prices, int buy, vector<vector<int>>& dp){
        int n = prices.size();
        if(ind==n-1){
            if(!buy) return prices[ind];
            return 0;
        }
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(!buy) return dp[ind][buy] = max(rec(ind+1,prices,buy,dp),prices[ind] + rec(ind+1,prices,1-buy,dp));
        return dp[ind][buy] = max(-prices[ind]+rec(ind+1,prices,1-buy,dp),rec(ind+1,prices,buy,dp));
        
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        vector<int> prev(2,0), cur(2,0);
        prev[0] = prices[n-1];
        prev[1] = 0;
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<2;j++){
                if(!j) cur[j] = max(prev[j],prices[i]+prev[1-j]);
                else cur[j] = max(-prices[i]+prev[1-j],prev[j]);
            }
           prev = cur;
        }
        return prev[1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends