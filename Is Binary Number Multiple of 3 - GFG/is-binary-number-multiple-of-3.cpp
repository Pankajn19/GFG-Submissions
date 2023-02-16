//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int isDivisible(string s){
	    int n = s.size();
	    int rem =0;
	    for(int i=n-1;i>=0;i--){
	        if(s[i]=='1'){
	            int x = n-1-i;
	            if(x%2){
	                rem+=2;
	                rem%=3;
	            }
	            else{
	                rem++;
	                rem%=3;
	        }
	    }
	    }
	    if(rem) return 0;
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends