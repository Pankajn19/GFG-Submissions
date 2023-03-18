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
    vector<int> getDistinctDifference(int n, vector<int> &a) {
        unordered_set<int> s;
        vector<int> left;
        left.push_back(0);
        for(int i=1;i<n;i++){
            s.insert(a[i-1]);
            left.push_back(s.size());
        }
        unordered_set<int> ns;
        vector<int> right;
        right.push_back(0);
        for(int i=n-2;i>=0;i--){
            ns.insert(a[i+1]);
            right.push_back(ns.size());
        }
        reverse(right.begin(), right.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++) ans[i] = left[i] - right[i];
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends