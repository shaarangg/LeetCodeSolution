class Solution {
public:
    vector<vector<int>> ans;
    void util(vector<int> &candidates, int target, int N, vector<int> arr){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(N==0) return;
        util(candidates, target, N-1, arr);
        if(candidates[N-1]<=target){
            arr.push_back(candidates[N-1]);
            util(candidates, target-candidates[N-1], N, arr);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        util(candidates,target,n,{});
        return ans;
    }
};