class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> n(nums.begin(),nums.end());
        int maxCount=0;
        for(auto i: n){
            if(n.find(i-1)==n.end()){
                int count=1;
                while(n.find(i+1)!=n.end()){
                    count++;
                    i++;
                }
                maxCount = max(maxCount,count);
            }
        }
     return maxCount;   
    }
};