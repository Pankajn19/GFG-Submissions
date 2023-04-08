//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string s)
    {
         char s1 = '[';
        char s2 = '{';
        char s3 = '(';
        char s4 =  ']';
        char s5 =  '}';
        char s6 = ')';
        stack<char> ps;
        for(int i=0;i<s.size();i++){
            if(s[i]==s1 || s[i]==s2 || s[i]==s3){
                ps.push(s[i]);
                }
            else if(s[i]==s4){
                if(ps.empty()){
                    return false;
                }
                else if(ps.top()==s1){
                    ps.pop();
                }
                else return false;
                
            }
            else if(s[i]==s5){
                 if(ps.empty()){
                    return false;
                }
                else if(ps.top()==s2){
                    ps.pop();
                }
                else return false;
            }
             else if(s[i]==s6){
                 if(ps.empty()){
                    return false;
                }
                else if(ps.top()==s3){
                    ps.pop();
                }
                else return false;
            }
           
        }
        return ps.empty();
        }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends