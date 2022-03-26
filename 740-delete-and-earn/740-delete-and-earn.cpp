class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int mn = *max_element(nums.begin(),nums.end());
        int arr[mn+1];
        memset(arr,0,sizeof(arr));
        for(int i=0; i<n; i++){
            arr[nums[i]]+=nums[i];
        }
        int dp[mn+1];
        dp[0]=0;
        dp[1]=arr[1];
        for(int i=2; i<=mn; i++){
            dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
        }
        return dp[mn];
    }
};