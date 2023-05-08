//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        int modulo(string str,int k){
        int n = str.size();
        int pwrTwo[n];
        pwrTwo[0] = 1 % k;
        for (int i = 1; i < n; i++){
        pwrTwo[i] = pwrTwo[i - 1] * (2 % k);
        pwrTwo[i] %= k;
         }
        int res = 0;
        int i = 0, j = n - 1;
        while (i < n){
        if (str[j] == '1'){
            res += (pwrTwo[i]);
            res %= k;
        }
        i++;
        j--;
        }
        return res;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends