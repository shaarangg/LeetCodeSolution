class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int rsum=0,lsum=0;
        for(auto i: nums) rsum+=i;
        for(int i=0; i<n; i++){
            if(lsum==rsum-lsum-nums[i]) return i;
            lsum+=nums[i];
        }
        return -1;
    }
};