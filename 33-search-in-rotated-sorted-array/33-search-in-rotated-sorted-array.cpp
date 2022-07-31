class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int lo = 0, hi=n-1;
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(mid!=0 && nums[mid]<nums[mid-1]){
                lo=mid;
                break;
            }
            else if(mid!=n-1 && nums[mid]>nums[mid+1]){
                lo=mid+1;
                break;
            }
            else if(nums[mid]<nums[lo]) hi = mid-1;
            else if(nums[mid]>nums[hi]) lo=mid+1;
            else break;
        }
        cout<<lo;
        if(target==nums[lo]) return lo;
        if(target<=nums[n-1]){
            hi=n-1;
        }
        else {
            hi=lo-1;
            lo=0;
        }
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid]==target) return mid;
            else if(target>nums[mid]) lo=mid+1;
            else hi=mid-1;
        }
        return -1;
    }
};