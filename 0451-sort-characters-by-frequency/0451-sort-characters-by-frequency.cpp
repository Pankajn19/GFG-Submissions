class Solution {
public:
    string frequencySort(string s) {
      unordered_map<char, int> mp;
      for(int i=0;i<s.size();i++) mp[s[i]]++;
      priority_queue<pair<int,int>> pq;
      for(auto it : mp) pq.push({it.second, it.first});
      string ans;
      while(pq.size()){
        int x = pq.top().first;
        while(x--) ans+=pq.top().second;
        pq.pop();
      }
      return ans;
        
    }
};