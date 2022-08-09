class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        if(n==0) return {newInterval};
        bool flag=false;
        for(int i=0; i<n; i++){
            if(newInterval[0]<=intervals[i][0]){
                flag=true;
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }
        if(!flag) intervals.push_back(newInterval);
        for(auto i: intervals) cout<<i[0]<<" "<<i[1]<<endl;
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1; i<=n; i++){
            if(intervals[i][0]<=ans.back()[1]) ans.back()[1]=max(intervals[i][1],ans.back()[1]);
            else ans.push_back(intervals[i]);
        }
        return ans;
    }
};