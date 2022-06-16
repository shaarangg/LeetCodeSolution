// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    static int cmp(pair<int,int> a, pair<int,int> b){
        return a.second<b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> meet;
        for(int i=0; i<n; i++){
            meet.push_back(make_pair(start[i],end[i]));
        }
        sort(meet.begin(),meet.end(),cmp);
        vector<pair<int,int>> ans;
        ans.push_back(meet[0]);
        for(int i=1; i<n; i++){
            if(ans.back().second<meet[i].first) ans.push_back(meet[i]);
        }
        return ans.size();
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends