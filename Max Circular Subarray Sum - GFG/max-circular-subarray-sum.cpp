//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int nums[], int n){
        long long min1 = INT_MIN;
        long long curr=0;
        int neg = 0;
        long long mini = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]<0) neg++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]>mini) mini = nums[i];
        }
        if(neg==n) return mini;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            if(min1<curr) min1 = curr;
            if(curr<0) curr=0;
        }
        for(int i=0;i<n;i++){
            nums[i] = ((-1)*nums[i]);
        }
        long long min2 = INT_MIN;
        curr=0;
        for(int i=0;i<n;i++){
             curr+=nums[i];
            if(min2<curr) min2 = curr;
            if(curr<0) curr=0;
        }
        long long total = 0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        long long min3 = total - min2;
        long long min4 = ((-1)*min3);
        if(neg==0) return ((-1)*total);
        return max(min1,min4);
        
        // your code here
    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends