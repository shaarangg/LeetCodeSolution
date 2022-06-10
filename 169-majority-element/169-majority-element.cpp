class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int elem=0;
        int count=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(count==0) elem=nums[i];
            count+= elem==nums[i]?1:-1;
        }
        return elem;
    }
};