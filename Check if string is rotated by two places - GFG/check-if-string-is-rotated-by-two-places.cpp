//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string s1, string s2)
    {
       string s3;
       for(int i=2;i<s1.size()+2;i++) s3+=s1[(i)%s1.size()];
       if(s3==s2) return true;
       string s4;
       for(int i=2;i<s2.size()+2;i++) s4+=s2[(i)%s2.size()];
       return s1==s4;
       
        
        
        
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends