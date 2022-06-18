class Solution {
public:
    vector<vector<int>> ans;
    void util(vector<int> &nums, vector<int> arr, int N){
        if(N==0){
            ans.push_back(arr);
            return;
        }
        util(nums, arr, N-1);
        arr.push_back(nums[N-1]);
        util(nums,arr,N-1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        util(nums,{},n);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};