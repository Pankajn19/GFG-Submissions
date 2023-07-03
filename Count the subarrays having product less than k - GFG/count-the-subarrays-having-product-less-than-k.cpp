//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution{
  public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        long long prod = 1;
        int ans = 0;
        int i =0,j=0;
        while(j<n){
            prod*=a[j];
            if(prod<k)  ans+=(j-i+1);
            else{
                while(i<=j && prod>=k ){
                    prod/=a[i];
                    i++;
                }
                if(i>j){
                    j=i;
                    prod = 1;
                    continue;
                }
                else ans+=(j-i+1);
            }
            j++;
        }
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends