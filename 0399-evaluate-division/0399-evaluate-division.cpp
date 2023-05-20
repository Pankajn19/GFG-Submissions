class Solution {
public:
    double bfs(string x, string y,  unordered_map<string,vector<pair<string,double>>>& adj){
      unordered_map<string,int> mp;
      mp[x] = 1;
      queue<pair<string,double>> q;
      q.push({x,1});
      while(!q.empty()){
        string s = q.front().first;
        double cur = q.front().second;
        q.pop();
        vector<pair<string,double>> tra  = adj[s];
        for(int i=0;i<tra.size();i++){
          string frac = tra[i].first;
          double val = tra[i].second;
          if(frac==y) return cur*val;
          if(mp[frac]==1) continue;
          mp[frac] = 1;
          q.push({frac,cur*val});
        }
      }
      return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& val, vector<vector<string>>& queries) {
      unordered_map<string,vector<pair<string,double>>> adj;
      for(int i=0;i<e.size();i++){
        string x = e[i][0];
        string y = e[i][1];
        adj[x].push_back({y,val[i]});
        adj[y].push_back({x,double(double(1)/double(val[i]))});
      }
      vector<double> ans;
      for(int i=0;i<queries.size();i++) ans.push_back(bfs(queries[i][0], queries[i][1],adj));       
      return ans;        
    }
};