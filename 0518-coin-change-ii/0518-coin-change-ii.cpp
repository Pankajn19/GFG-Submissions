class Solution {
public:
    int change(int amt, vector<int>& c) {
      int n = c.size();
      vector<int> prev(amt+1,0), cur(amt+1,0);
      for(int i=0;i<=amt;i++){
        if(i%c[0]==0) prev[i] = 1;
      }
      for(int i=1;i<n;i++){
        for(int j=0;j<=amt;j++){
          int ntk = prev[j];
          int tk = 0;
          if(c[i]<=j) tk =  cur[j-c[i]];      
          cur[j] = tk + ntk;

        }
          prev = cur;
      }
      return prev[amt];

     // return rec(n-1,c,amt,dp);
        
    }
};