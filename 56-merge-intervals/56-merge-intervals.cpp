class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ranges;
        ranges.push_back(intervals[0]);
        for(int i =1; i<n; i++){
            if(ranges.back()[1]>=intervals[i][0]) ranges.back()[1] = max(ranges.back()[1],intervals[i][1]);
            else ranges.push_back(intervals[i]);
        }
        return ranges;
    }
};