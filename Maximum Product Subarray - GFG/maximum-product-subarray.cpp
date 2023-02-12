//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    long long product(vector<int>& arr, int n){
        int neg = 0;
       
        for(int i=0;i<n;i++){
            if(arr[i]<0) neg++;
        }
        if(neg%2==0){
            long long prod = 1;
            for(int i=0;i<n;i++) prod*=arr[i];
            return prod;
        }
        int fn, ln;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                fn = i;
                break;
            }
        }
        for(int i=n-1;i>=0;i--){
            if(arr[i]<0){
                ln = i;
                break;
            }
        }
        long long suf = 1, pre = 1;
        for(int i=fn+1;i<n;i++) suf*=arr[i];
        for(int i=0;i<ln;i++) pre*=arr[i];
        return max(pre,suf);
         
    }
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    int pos = 0 , neg = 0, zer = 0;
	     if(n==1) return arr[0];
	    for(int i=0;i<n;i++){
	        if(!arr[i]) zer++;
	        else if(arr[i]>0) pos++;
	        else neg++;
	    }
	    if(zer==n) return 0;
	    if(pos==0){
	        if(zer) return 0;
	        else return product(arr,n);
	    }
	    vector<int> curr;
	    long long maxi = -1;
	    for(int i=0;i<n;i++){
	        if(arr[i]==0){
	            if(curr.size()){
	                maxi = max(maxi,product(curr,curr.size()));
	                curr.clear();
	            } 
	            else continue;
	        }
	        else curr.push_back(arr[i]);
	    }
	    maxi = max(maxi,product(curr,curr.size()));
	    return maxi;
	    
	    // code here
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends