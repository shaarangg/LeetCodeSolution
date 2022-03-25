class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        int cons[n],ncons[n];
        cons[0]=nums[0];
        ncons[0]=0;
        for(int i=1; i<n; i++){
            cons[i] = nums[i]+ncons[i-1];
            ncons[i] = max(cons[i-1],ncons[i-1]);
        }
        return max(cons[n-1],ncons[n-1]);
    }
};