// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int range=0;
	    for(int i=0; i<n; i++){
	        range+=arr[i];
	    }
	    int l = range/2;
	    bool table[n+1][l+1];
	    for(int i=0; i<=l; i++) table[0][i]=false;
	    for(int i=0; i<=n; i++) table[i][0]=true;
	    for(int i=1; i<=n; i++){
	        for(int j =1; j<=l; j++){
	            if(arr[i-1]<=j) table[i][j] = table[i-1][j] || table[i-1][j-arr[i-1]];
	            else table[i][j] = table[i-1][j];
	        }
	    }
	    int s1=0;
	    for(int i=1; i<=l; i++){
	        for(int j=1; j<=n; j++){
	            if(table[j][i]){
	                s1 = i;
	                break;
	            }
	        }
	    }
	    return range-2*s1;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends