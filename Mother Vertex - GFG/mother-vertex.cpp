//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	      vector<vector<int>> indeg(V); 

  
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            indeg[v].push_back(u); 
        }
    }
	    int mini = indeg[V-1].size();
	    int ind = V-1;
	    for(int i=V-2;i>=0;i--){
	        if(indeg[i].size()<=mini){
	            mini = indeg[i].size();
	            ind = i;
	        }
	    }
	    queue<int> q;
	    q.push(ind);
	    int cnt = 1;
	    vector<int> vis(V,0);
	    vis[ind]  = 1;
	    while(q.size()){
	        int x = q.front();
	        q.pop();
	        for(auto i : adj[x]){
	            if(!vis[i]){
	                q.push(i);
	                cnt++;
	                vis[i] = 1;
	            }
	        }
	    }
	    if(cnt!=V) return -1;
	    unordered_set<int> st;
	    while(q.size()) q.pop();
	    q.push(ind);
	    st.insert(ind);
	    while(q.size()){
	        int x = q.front();
	        q.pop();
	        for(auto i : indeg[x]){
	            if(st.find(i)==st.end()){
	                st.insert(i);
	                q.push(i);
	            }
	        }
	    }
	    int ans = ind;
	    for(auto i : st){
	        ans = min(ans,i);
	    }
	    return ans;
	   
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends