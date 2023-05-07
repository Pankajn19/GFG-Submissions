//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string s){
      int i = 0;
      int k = 0;
      while(i<s.size()-1 && s[i]>=s[i+1]) i++;
      while(k<s.size()-1 && s[k]>s[k+1]) k++;
      string ans;
      string ans1;
      for(int j=0;j<=i;j++) ans+=s[j];
      for(int j=0;j<=k;j++) ans1+=s[j];
      
      string x = ans;
      string y = ans1;
      reverse(ans.begin(), ans.end());
      reverse(ans1.begin(), ans1.end());
      if(x+ans<y+ans1) return x+ans;
      return y+ans1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends