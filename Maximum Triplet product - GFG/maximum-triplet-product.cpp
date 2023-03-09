//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
        if(n==3) return (arr[0]*arr[1]*arr[2]);
        sort(arr,arr+n);
        return max(arr[0]*arr[1]*arr[n-1], arr[n-1]*arr[n-2]*arr[n-3]);
        
       /* int neg = 0;
        for(int i=0;i<n;i++){
            if(arr[i]<0) neg++;
        }
        if(neg<=1){
            priority_queue<long long> pq(arr,arr+n);
            long long x = pq.top();
            pq.pop();
            long long y = pq.top();
            pq.pop();
            long long z = pq.top();
            pq.pop();
            return (x*y*z);
        }
         long long y = INT_MIN;
         for(int i=0;i<n;i++) y = max(y,arr[i]);
         
         */
         
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends