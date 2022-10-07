class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        if(n<4) return {};
        for(int i=0; i<n-3; i++){
            for(int j=i+1; j<n-2; j++){
                int s = j+1;
                int e = n-1;
                while(s<e){
                    long long sum = (long)nums[i]+(long)nums[j]+(long)nums[s]+(long)nums[e];
                    if(sum==target){
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[s]);
                        temp.push_back(nums[e]);
                        st.insert(temp);
                    }
                    if(sum>target) e--;
                    else s++;
                }
            }
        }
        vector<vector<int>> ans;
        for(auto i: st) ans.push_back(i);
        return ans;
    }
};