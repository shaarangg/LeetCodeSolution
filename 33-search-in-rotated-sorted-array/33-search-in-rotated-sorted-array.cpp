class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int high=n,low=0;
        int mid =0;
        while(low<=high){
            mid = low + (high-low)/2;
            if(mid>low && nums[mid-1]>nums[mid]) break;
            else if(mid<high && nums[mid+1]<nums[mid]){
                mid+=1;
                break;
            }
            else if(nums[mid]>nums[high]) low = mid+1;
            else high = mid-1;
        }
        cout<<mid;
        high=n;
        low=0;
        if(target<=nums[high]) low = mid;
        else high=mid-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(target==nums[mid]) return mid;
            else if(target<nums[mid]) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};