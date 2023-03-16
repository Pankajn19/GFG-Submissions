//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

long long int no_of_subarrays(int n, vector<int> &arr) {
    int x = 0;
    while(x<n && arr[x]==1) x++;
    if(x==n) return 0;
    int i = x;
    long long int ans = 0;
    while(i<n){
        int j = i+1;
        long long int curr = 1;
        while(j<n && arr[j]==0){
            curr++;
            j++;
        }
        ans+=(curr)*(curr+1)/2;
        i=j+1;
        while(arr[i]==1 && i<n) i++;
    }
    return ans;
   
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << no_of_subarrays(n, arr) << endl;
    }
}

// } Driver Code Ends