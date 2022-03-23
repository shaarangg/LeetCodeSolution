class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        unordered_map<int, vector<int>> dict;
        int l = nums.size();
        for(int i=0; i<l; i++){
            
            if(dict.find(nums[i])==dict.end()){
                vector<int> temp;
                temp.push_back(i);
                dict[nums[i]] = temp;
            }
            else{
                dict[nums[i]].push_back(i);
            }
        }
        // for(auto i: dict){
        //     cout<<i.first<<" ";
        //     for(auto j: i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0; i<l; i++){
            vector<int> temp;
            int rem = target-nums[i];
            if(dict.find(rem)!=dict.end()){
                temp = dict[rem];
                if(temp.size()==1 && temp[0]==i) continue;
                else if(temp.size()==1){
                    ans[0]=i;
                    ans[1]=temp[0];
                }
                else{
                    ans[0]=i;
                    ans[1]=temp[1];
                }
                break;
            }
        }
        return ans;
    }
};