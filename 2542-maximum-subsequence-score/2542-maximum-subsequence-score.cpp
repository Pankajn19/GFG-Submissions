class Solution {
public:
    
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
      int n = nums1.size();
      vector<pair<int,int>> vec;
      for(int i=0;i<n;i++) vec.push_back({nums2[i], nums1[i]});
      sort(vec.rbegin(), vec.rend());
      long long sum = 0;
      long long mini = 0;
      long long ans = 0;
      for(int i=0;i<k;i++)  sum+=vec[i].second;
      mini = vec[k-1].first;
      ans = sum*mini;
      priority_queue<int,vector<int>,greater<int>> pq;
      for(int i=0;i<k;i++) pq.push(vec[i].second);
      for(int i=k;i<n;i++){
        long long x = pq.top();
        pq.pop();
        sum-=x;
        sum+=vec[i].second;
        mini = vec[i].first;
        ans = max(ans,sum*mini);
        pq.push(vec[i].second);
      }
      return ans;

      
        
    }
};