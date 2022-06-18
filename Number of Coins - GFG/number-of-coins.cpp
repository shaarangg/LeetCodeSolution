// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    int table[V+1];
	    memset(table,-1,sizeof(table));
	    table[0]=0;
	    for(int i=0; i<M; i++){
	        for(int j=0; j<V; j++){
	            if(j+coins[i]<=V && table[j]!=-1){
	                if(table[j+coins[i]]==-1) table[j+coins[i]] = 1+table[j];
	                else table[j+coins[i]] = min(table[j+coins[i]], 1+table[j]);
	            }
	        }
	    }
	    return table[V];
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends