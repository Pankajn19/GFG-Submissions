//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        int maxl(vector<int>& arr, int n){
            int neg = 0, pos = 0;
            for(int i=0;i<n;i++){
                if(arr[i]>0) pos++;
                else neg++;
            }
            if(neg%2==0) return n;
            int fn;
            for(int i=0;i<n;i++){
                if(arr[i]<0){
                    fn=i;
                    break;
                }
            }
            int bn;
            for(int i=n-1;i>=0;i--){
                if(arr[i]<0){
                    bn = i;
                    break;
                }
            }
            return max(n-fn-1,bn);
            
        }
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
             vector<int> curr;
             int maxi = INT_MIN;
            for(int i=0;i<n;i++){
                if(arr[i]!=0){
                    curr.push_back(arr[i]);
                }
                else{
                    maxi = max(maxi, maxl(curr,curr.size()));
                    curr.clear();
                }
                
            }
            maxi = max(maxi,maxl(curr,curr.size()));
            
            return maxi;
            
           //code here
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends