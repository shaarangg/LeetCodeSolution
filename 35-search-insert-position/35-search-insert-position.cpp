class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = nums.size()-1;
        int low = 0, high = l;
        int idx=-1;
        if(target>nums[l]) return l+1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]==target) return mid;
            if(target>nums[mid]) low=mid+1;
            else{
                high=mid-1;
                idx=mid;
            }
        }
        return idx;
    }
};