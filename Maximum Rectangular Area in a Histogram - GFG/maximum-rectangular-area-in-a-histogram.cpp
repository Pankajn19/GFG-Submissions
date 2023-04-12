//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
      stack<pair<long long,int>> st;
      vector<long long> nsm;
      nsm.push_back(-1);
      st.push({arr[n-1],n-1});
      for(int i=n-2;i>=0;i--){
          if(st.empty()){
              nsm.push_back(-1);
              st.push({arr[i],i});
          }
          else{
              while(st.size() && st.top().first>=arr[i]) st.pop();
              if(st.size()){
                  nsm.push_back(st.top().second);
                  st.push({arr[i],i});
             }
              else{
                  nsm.push_back(-1);
                  st.push({arr[i],i});
              }
          }
      }
      reverse(nsm.begin(), nsm.end());
      while(st.size()) st.pop();
      vector<long long> psm;
      psm.push_back(-1);
      st.push({arr[0],0});
      for(int i=1;i<n;i++){
          if(st.empty()){
              psm.push_back(-1);
              st.push({arr[i],i});
          }
          else{
              while(st.size() && st.top().first>=arr[i]) st.pop();
              if(st.size()) psm.push_back(st.top().second);
              else psm.push_back(-1);
              st.push({arr[i],i});
          }
      }
      vector<long long> maxd(n);
      if(nsm[0]==-1) maxd[0] = n;
      else maxd[0] = nsm[0];
      if(psm[n-1]==-1) maxd[n-1] = n;
      else maxd[n-1] = n-1-psm[n-1];
      for(int i=1;i<n-1;i++){
          if(arr[i-1]<arr[i] && arr[i+1]<arr[i]) maxd[i] = -1;
          else if(psm[i]==-1 && nsm[i]==-1) maxd[i] = n;
          else if(psm[i]==-1) maxd[i] = nsm[i]; 
          else if(nsm[i]==-1) maxd[i] = n-psm[i]-1; 
          else maxd[i] = nsm[i]-psm[i]-1;
      }
      long long ans = 0;
      long long cur = 0;
      for(int i=0;i<n;i++){
          if(maxd[i]==-1) continue;
          long long h = arr[i];
          long long b = maxd[i];
          cur = h*b;
          ans=max(ans,cur);
          
      }
      return ans;
      
    // return psm[6];
      
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends