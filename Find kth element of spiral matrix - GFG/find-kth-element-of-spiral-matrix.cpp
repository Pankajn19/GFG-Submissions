//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
class Solution
{
    public:
    /*You are required to complete this method*/
    int findK(int a[MAX][MAX],int n,int m,int k)
    {
 	      int cnt = 0, minR = 0, minC = 0, maxR = n, maxC = m;
 	      while(true){
 	          for(int i=minC;i<maxC;i++){
 	              cnt++;
 	              if(k==cnt) return a[minR][i];
 	          }
 	          minR++;
 	          for(int i=minR;i<maxR;i++){
 	              cnt++;
 	              if(k==cnt) return a[i][maxC-1];
 	          }
 	          maxC--;
 	          for(int i=maxC-1;i>=minC;i--){
 	              cnt++;
 	              if(k==cnt) return a[maxR-1][i];
 	          }
 	          maxR--;
 	          for(int i=maxR-1;i>=minR;i--){
 	              cnt++;
 	              if(k==cnt) return a[i][minC];
 	          }
 	          minC++;
 	      }
    }
};





//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n,m;
        int k=0;
        //cin>>k;
        cin>>n>>m>>k;
        int a[MAX][MAX];
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>a[i][j];
            }
        }
        Solution ob;
        cout<<ob.findK(a,n,m,k)<<endl;
        
       
    }
}
// } Driver Code Ends