//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a,int n)
        {
          int i = 0;
          while(i<n){
              int j = i+1;
              while(j<n && ((a[j]%2) == (a[i]%2))){
                  j++;
              }
              if(j==n){
                  sort(a.begin()+i,a.begin()+j);
                  reverse(a.begin()+i,a.begin()+j);
                  return a;
              }
              sort(a.begin()+i, a.begin()+j);
              reverse(a.begin()+i, a.begin()+j);
              i=j;
          }
          return a;
        }
        
        
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends