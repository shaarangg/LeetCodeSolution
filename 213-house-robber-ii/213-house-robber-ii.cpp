class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int cons[n], ncons[n];
        cons[0]=nums[0];
        ncons[0]=0;
        int m = 0;
        for(int i=1; i<n-1; i++){
            cons[i]=nums[i]+ncons[i-1];
            ncons[i] = max(cons[i-1],ncons[i-1]);
        }
        m = max(cons[n-2],ncons[n-2]);
        cons[0]=0,ncons[0]=0;
        for(int i=1; i<n; i++){
            cons[i]=nums[i]+ncons[i-1];
            ncons[i] = max(cons[i-1],ncons[i-1]);
        }
        m = max(m,max(ncons[n-1],cons[n-1]));
        return m;
    }
};