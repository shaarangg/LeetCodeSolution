class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ms = 0;
        int negmax = INT_MIN;
        int local_sum=0;
        for(auto i: nums){
            if(i<=0) negmax = max(negmax,i);
            local_sum +=i;
            ms = max(ms, local_sum);
            if(local_sum<0) local_sum=0;
        }
        if(ms==0) return negmax;
        else return ms;
    }
};