class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& q) {
        vector<int> ans(q.size(),0);
        vector<int> c(n,0);
        c[q[0][0]] = q[0][1];
        int cnt = 0;
        if(n==1) return ans;
        for(int i=1;i<q.size();i++){
            int x =   q[i][0];
            int clr = q[i][1];
            int cur = 0;
            int old = 0;
            if(x==0){
                if(c[x]!=0 && c[x+1]==c[x]) old++;
                c[x] = clr;
                if(c[x]!=0 && c[x+1]==c[x]) cur++;
                cnt+=(cur-old);
            }
            else if(x==n-1){
                if(c[x]!=0 && c[x-1]==c[x]) old++;
                c[x] = clr;
                if(c[x]!=0 && c[x-1]==c[x]) cur++;
                cnt+=(cur-old);
                
            }
            else{
                if(c[x]!=0 && c[x+1]==c[x]) old++;
                if(c[x]!=0 && c[x-1]==c[x]) old++;                
                c[x] = clr;
                if(c[x]!=0 && c[x+1]==c[x]) cur++;
                if(c[x]!=0 && c[x-1]==c[x]) cur++;                
                cnt+=(cur-old);
                
            }
            ans[i] = cnt;
        }
        return ans;
    }
};