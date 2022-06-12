class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int pos2 = n-1;
        int pos1=0;
        int pos0 = 0;
        while(pos1<=pos2){
            if(nums[pos1]==2){
                swap(nums[pos1],nums[pos2]);
                pos2--;
            }
            else if(nums[pos1]==1){
                pos1++;
            }
            else if(nums[pos1]==0){
                swap(nums[pos1],nums[pos0]);
                pos0++;
                pos1++;
            }
        }
    }
};