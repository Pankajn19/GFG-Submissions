class Solution {
public:
    int addMinimum(string word) {
          string x = "abc";
        int i=0,j=0;
        int ans = 0;
        while(j<word.size() ){
            if(word[j]==x[i%3]){
                j++;
                i++;
            }
            else{
                ans++;
                i++;
            }
             }
        if(i%3==2) ans++;
        else if(i%3==1) ans+=2;
        return ans;
        
    }
};