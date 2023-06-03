//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            int n = s.size();
            vector<string> num, op;
            int i=0;
            while(i<n){
                string cur;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    cur+=s[i];
                    i++;
                }
                if(cur!="") num.push_back(cur);
                i++;
            }
            i = 0;
            while(i<n ){
                string cur;
                while(i<n && (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/')){
                    cur+=s[i];
                    i++;
                }
                if(cur!="") op.push_back(cur);
                i++;
            }
            reverse(num.begin(), num.end());
            reverse(op.begin(), op.end());
             i=0;
             int j = 0;
            vector<string> ans;
            while(i<num.size() && j<op.size()){
                ans.push_back(num[i]);
                ans.push_back(op[j]);
                i++;
                j++;
            }
            ans.push_back(num[num.size()-1]);
            string answer;
            for(int k=0;k<ans.size();k++) answer+=ans[k];
            return answer;
            
            
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends