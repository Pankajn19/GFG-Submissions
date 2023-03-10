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
      long long i1;
      long long min1 =  LONG_MAX;
      for(int i=0;i<n;i++){
          if(arr[i]<min1) {
              min1=arr[i];
              i1=i;
          }
      }
      long long i2;
      long long min2 = LONG_MAX;
      for(long long i=0;i<n;i++){
          if(i==i1) continue;
          else if(arr[i]<min2){
              min2 = arr[i];
              i2=i;
          }
      }
      long long max1 =  LONG_MIN;
      long long i3;
      for(long long i=0;i<n;i++){
          if(arr[i]>max1){
              i3=i;
              max1 = arr[i];
          }
      }
      long long max2 =  LONG_MIN;
      long long i4;
      for(long long i=0;i<n;i++){
          if(i==i3) continue;
          else if(arr[i]>max2){
              i4=i;
              max2 = arr[i];
          }
      }
      long long max3  =  LONG_MIN;
      long long i5;
      for(long long i=0;i<n;i++){
          if(i==i3 || i==i4) continue;
          else if(arr[i]>max3){
              max3 = arr[i];
              i5=i;
          }
      }
      return max(max1*max2*max3, min1*min2*max1);
         
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