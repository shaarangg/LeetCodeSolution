class Solution {
public:
    unordered_map<int, int> dict;
    bool containsDuplicate(vector<int>& nums) {
        for(auto i: nums){
            if(dict.find(i)==dict.end()) dict[i]=1;
            else{
                return true;
            }
        }
        return false;
    }
};