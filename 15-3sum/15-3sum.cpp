class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        unordered_map<int,vector<int>> dict;
        for(int i=0; i<n; i++) dict[nums[i]].push_back(i);
        int sum=0;
        for(int i =0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            for(int j=i+1; j<n; j++){
                if ( j > i+1 && nums[j-1] == nums[j] ) continue;
                sum=nums[i]+nums[j];
                if(dict.find(-sum)!=dict.end()){
                    for(auto k: dict[-sum]){
                        if(k>i && k>j){
                            vector<int> temp;
                            temp.push_back(nums[i]);
                            temp.push_back(nums[j]);
                            temp.push_back(nums[k]);
                            ans.push_back(temp);
                            break;
                        }
                    }
                }
            }
        }
        return ans;
    }
};