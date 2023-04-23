//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        int n = arr.size();
        vector<int> left;
        stack<int> s;
        for(int i=0;i<n;i++){
        while (!s.empty() && arr[s.top()] >= arr[i])   s.pop();
        if (s.empty()) left.push_back(-1);
        else  left.push_back(s.top());
        s.push(i);
    }
        while(!s.empty()) s.pop();
        vector<long long> right;  
        for(int i=n-1;i>=0;i--){
            if(s.empty()){
               s.push(i);
               right.push_back(-1);
            }
            else{
                while(s.size() && arr[s.top()]>=arr[i])    s.pop();
                if(s.empty()) right.push_back(-1);
                else right.push_back(s.top());
                s.push(i);
            }
        }
        reverse(right.begin(), right.end());
        vector<int> ans(n);
        if(right[0]==-1) ans[0] = -1;
        else ans[0] = right[0];
        if(left[n-1]==-1) ans[n-1] = -1;
        else ans[n-1] =  left[n-1];
        
        for(int i=1;i<n-1;i++){
            if(right[i]==-1 && left[i]==-1) ans[i] = -1;
            else if(right[i]==-1 || left[i]==-1){
                if(right[i]==-1) ans[i] = left[i];
                else ans[i] = right[i];
            }
            else if(abs(right[i]-i) == abs(left[i]-i)){
                    if(arr[right[i]]>=arr[left[i]]) ans[i] = left[i];
                    else  ans[i] = right[i];
                }
            else if(abs(right[i]-i) < abs(left[i]-i)) ans[i] = right[i];
            else if(abs(right[i]-i) > abs(left[i]-i)) ans[i]= left[i];
            
            
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends