//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    pair<long,long> indexes(vector<long long> nums, long long target)
    {
        long long n = nums.size();
      long long i=0,j=n-1;
      long long low = -1, high = -1;
      while(i<=j){
        long long mid = (i+j)/2;
        if(nums[mid]==target){
          low = mid;
          j = mid-1;
        }
        else if(nums[mid]<target) i = mid+1;
        else j = mid-1;
      }
      i=0, j = n-1;
        while(i<=j){
        long long mid = (i+j)/2;
        if(nums[mid]==target){
          high = mid;
          i = mid+1;
        }
        else if(nums[mid]<target) i = mid+1;
        else j = mid-1;
      }
      return {low,high};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends