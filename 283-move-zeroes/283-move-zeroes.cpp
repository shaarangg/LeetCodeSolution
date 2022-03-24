class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int count=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0) count++;
            else nums[i-count]=nums[i];
        }
        while(count>0){
            nums[n-count]=0;
            count--;
        }
    }
};