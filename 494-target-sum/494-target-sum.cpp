class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target = abs(target);
        int n = nums.size();
        int sum=0;
        int z = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(nums[i]==0) z++;
        }
        if((target+sum)%2==0 && target<=sum)
        {
            target=(target+sum)/2;
            int dp[n+1][target+1];
            for(int j=0; j<=target; j++) dp[0][j]=0;
            for(int i=0; i<=n; i++) dp[i][0] = 1;
            for(int i=1; i<=n; i++){
                for(int j=1; j<=target; j++){
                    if(nums[i-1]>j || nums[i-1]==0) dp[i][j] = dp[i-1][j];
                    else{
                        dp[i][j] = dp[i-1][j-nums[i-1]] + dp[i-1][j];
                    } 
                }
            }
            return pow(2,z)*dp[n][target];
        } 
        else {
            return 0;
        }
        
    }
};