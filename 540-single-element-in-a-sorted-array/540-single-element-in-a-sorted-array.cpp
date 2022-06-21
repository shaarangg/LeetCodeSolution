class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int high = nums.size()-1;
        if(high==0 || nums[0]!=nums[1]) return nums[0];
        if(nums[high]!=nums[high-1]) return nums[high];
        int low = 0;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(mid%2==0 && nums[mid]==nums[mid+1] || mid%2!=0 && nums[mid]==nums[mid-1]) low = mid+1;
            else high = mid-1;
        }
        return nums[low];
    }
};