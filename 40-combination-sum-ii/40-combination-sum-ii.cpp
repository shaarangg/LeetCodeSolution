class Solution {
public:
    vector<vector<int>> ans;
    void util(vector<int> &candidates, int target,int N, vector<int> arr){
        if(target==0){
            ans.push_back(arr);
            return;
        }
        if(N==0) return;
        if(candidates[N-1]<=target){
            arr.push_back(candidates[N-1]);
            util(candidates, target-candidates[N-1],N-1,arr);
            arr.pop_back();
        }
        N--;
        while(N>0 && candidates[N]==candidates[N-1]) N--;
        util(candidates, target,N,arr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(),candidates.end());
        util(candidates, target, n,{});
        return ans;
    }
};