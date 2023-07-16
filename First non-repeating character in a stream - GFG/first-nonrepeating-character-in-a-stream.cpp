//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string a){
		   vector<pair<int,int>> freq(26,{0,INT_MAX});
		   string ans;
		   ans+=a[0];
		   freq[a[0]-'a'].first++;
		   freq[a[0]-'a'].second = 0;
		   for(int i=1;i<a.size();i++){
		     char x = a[i];
		     freq[a[i]-'a'].first++;
		     if((freq[a[i]-'a']).first==1) freq[a[i]-'a'].second = i; 
		     if(a[i-1]=='#'){
		         if(freq[x].first==1) ans+=x;
		         else ans+='#';
		     }
		     else{
		         int mini = INT_MAX;
		         char y = '#';
		         for(int j=0;j<26;j++){
		             if(freq[j].first==1){
		                 if(freq[j].second<mini) {
		                     y = j+'a';
		                     mini = freq[j].second;
		                 }
		             }
		         }
		         ans+=y;

		         
		     }
		    
		   }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends