//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int nums[], int size)
    {
        int cnt=0;
        int x;
        for(int i=0;i<size;i++){
                 if(cnt==0){
                     x=nums[i];
                     cnt++;
                 }
             else if(x!=nums[i]){
                 cnt--;
             }
            else cnt++;
            }
     cnt  = 0;
    for(int i=0;i<size;i++){
        if(nums[i]==x) cnt++;
    }
    
        if(cnt<=size/2) return -1;
        return x;
        
        // your code here
        
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends