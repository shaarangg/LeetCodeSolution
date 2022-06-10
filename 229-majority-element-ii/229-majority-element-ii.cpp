class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int x= floor(nums.size()/3);
        unordered_map<int,int> dict;
        for(auto i:nums){
            dict[i]+=1;
        }
        vector<int> res;
        for(auto i:dict){
            if(i.second>x) res.push_back(i.first);
        }
        return res;
    }
};