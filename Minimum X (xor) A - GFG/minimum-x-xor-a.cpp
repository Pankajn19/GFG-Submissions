//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int btd(string n)
{
    string num = n;
    int dec_value = 0;
    int base = 1;
    int len = num.length();
    for (int i = len - 1; i >= 0; i--) {
        if (num[i] == '1')
            dec_value += base;
        base = base * 2;
    }
     return dec_value;
}
    long long minVal(long long a, long long b) {
        long long set = __builtin_popcount(b);
        long long total = int(log2(a)) + 1;
        long long zer = total - set;
        string ans = "";
        long long n = (int)(log2(a));
        string test = bitset<64>(a).to_string().substr(64 - n- 1);
        for(long long i=0;i<test.size();i++){
            if(test[i]=='1'){
                if(set){
                    ans+='1';
                    set--;
                }
                else{
                    ans+='0';
                    zer--;
                }
            }
            else {
                if(zer){
                    ans+='0';
                    zer--;
                }
                else{
                    ans+='1';
                    set--;
                }
            }
            
        }
        return btd(ans);
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.minVal(a, b);

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends