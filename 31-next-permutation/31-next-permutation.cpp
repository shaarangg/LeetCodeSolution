class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return;
        int i = n-1;
        while(i>0){
            if(nums[i]>nums[i-1]) break;
            i--;
        }
        if(i==0) reverse(nums.begin(), nums.end());
        else{
            for(int j=n-1; j>=i; j--){
                if(nums[i-1]<nums[j]){
                    int temp = nums[i-1];
                    nums[i-1] = nums[j];
                    nums[j] = temp;
                    break;
                }
            }
        }
        sort(nums.begin()+i, nums.end());
    }
};