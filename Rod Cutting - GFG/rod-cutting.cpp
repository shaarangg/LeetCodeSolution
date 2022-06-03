// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        int table[n+1][n+1];
        for(int i=0; i<=n; i++) table[i][0]=0;
        for(int i=0; i<=n; i++) table[0][i]=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(i<=j) table[i][j] = max(price[i-1] + table[i][j-i], table[i-1][j]);
                else table[i][j]=table[i-1][j];
            }
        }
        return table[n][n];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends