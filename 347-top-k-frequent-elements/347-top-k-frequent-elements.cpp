class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> dict;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> h;
        for(auto i: nums){
            dict[i]+=1;   
        }
        for(auto i: dict){
            if(k){
                h.push({i.second,i.first});
                k--;
            } else{
                if(i.second>h.top().first){
                    h.pop();
                    h.push({i.second,i.first});
                }
            }
        }
        vector<int> ans;
        while(!h.empty()){
            ans.push_back(h.top().second);
            h.pop();
        }
        return ans;
    }
};