class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        ans.push_back(nums);
        while(true){
            int i = n-1;
            while(i>0){
                if(nums[i-1]<nums[i]) break;
                i--;
            }
            if(i==0) break;
            for(int j=n-1; j>=i; j--){
                if(nums[j]>nums[i-1]){
                    swap(nums[j],nums[i-1]);
                    sort(nums.begin()+i,nums.end());
                    ans.push_back(nums);
                    break;
                }
            }
        }
        return ans;
    }
};