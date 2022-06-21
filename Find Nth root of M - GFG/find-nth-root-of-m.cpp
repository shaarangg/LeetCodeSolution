// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int m)
	{
	     if(n==1) return m;
	     if(m==1) return 1;
	     int left = 1, right=sqrt(m);
	     while(left<=right){
	         int mid = left + (right-left)/2;
	         int temp = n;
	         long long val=1;
	         while(temp--){
	             val*=mid;
                 if(val > m*1LL) break;
	         }
	         if(val==m) return mid;
	         else if(val>m) right = mid-1;
	         else left = mid+1;
	     }
	     return -1;
	}  
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends