//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int nums[], int n)
    {
          if(n==1) return nums[0]; 
        if(n==2) return max(nums[0],nums[1]);
      //  vector<int> dp(n,-1);
       // return rec(n-1,nums,dp);
        int prev1 = nums[0];
        int prev2 = max(nums[0],nums[1]);
        int curr;
       for(int i=2;i<n;i++){
           int x = prev1 + nums[i];
           int y = prev2;
           curr = max(x,y);
           prev1 = prev2;
           prev2 = curr;
       }
       return curr;
        // Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends