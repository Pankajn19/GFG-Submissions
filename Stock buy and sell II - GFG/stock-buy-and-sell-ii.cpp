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

    int stockBuyAndSell(int n, vector<int> &prices) {
        int prev1,prev2,cur1,cur2;
        prev1 = prices[n-1];
        prev2 = 0;
        for(int i=n-2;i>=0;i--){
           cur1 = max(prev1,prices[i]+prev2);
           cur2 = max(-prices[i]+prev1,prev2);
           prev1 = cur1;
           prev2 = cur2;
        }
        return prev2;
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