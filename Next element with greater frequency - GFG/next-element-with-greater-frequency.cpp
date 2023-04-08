//{ Driver Code Starts
#include <bits/stdc++.h>
#define N 10000
using namespace std;


// } Driver Code Ends
class Solution{
public:
    vector<int> print_next_greater_freq(int arr[],int n)
    {
        vector<int> ans;
        ans.push_back(-1);
        unordered_map<int,int> mp;
        stack<int> s;
        s.push(arr[n-1]);
        for(int i=0;i<n;i++) mp[arr[i]]++;
        for(int i=n-2;i>=0;i--){
            if(s.empty()) s.push(arr[i]);
            else{
                while(s.size() && (mp[s.top()]<=mp[arr[i]] || s.top()==arr[i])) s.pop();
                if(s.empty())  ans.push_back(-1);
                else ans.push_back(s.top());
                s.push(arr[i]);
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.

int main()
{
    int arr[N];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans=ob.print_next_greater_freq(arr,n);
        for(auto x:ans){
            cout<<x<<" ";
        }
        cout << endl;
    }
	return 1;
}

// } Driver Code Ends