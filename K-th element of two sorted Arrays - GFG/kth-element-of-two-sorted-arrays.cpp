// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    static int count(int arr[],int val, int n){
        int lo = 0;
        int hi = n-1;
        int ans=0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(arr[mid]<val){
                ans = mid+1;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return ans;
    }
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int lo,hi,ans=0;
        if(n==0){
            lo=arr2[0];
            hi=arr2[m-1];
        }
        else if(m==0){
            lo=arr1[0];
            hi=arr1[n-1];
        }
        else{
            lo = min(arr1[0],arr2[0]);
            hi = max(arr1[n-1],arr2[m-1]);
        }
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            int c = count(arr1,mid,n) + count(arr2,mid,m);
            // cout<<mid<<" "<<c<<endl;
            if(c<=k-1){
                lo=mid+1;
                ans=mid;
            } 
            else hi = mid-1;
        }
        return ans;
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends