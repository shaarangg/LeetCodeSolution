class Solution {
public:
    bool res(int idx, int K, unordered_map<int, int> &dict,unordered_map<string,bool> &dp, int n){
        if(idx==n) return true;
        if(idx>n) return false;
        if(dict[idx]!=1) return false;
        string key = to_string(idx)+":"+to_string(K);
        if(dp.find(key)!=dp.end()) return dp[key];
        if(K==1){
            return dp[key]=res(idx+K,K,dict,dp,n) || res(idx+K+1,K+1,dict,dp,n);
        }
        return dp[key]=res(idx+K-1,K-1,dict,dp,n) || res(idx+K,K,dict,dp,n) || res(idx+K+1,K+1,dict,dp,n);
    }
    bool canCross(vector<int>& stones) {
        unordered_map<int, int> dict;
        unordered_map<string,bool> dp;
        int target = stones[stones.size()-1];
        for(auto i: stones){
            dict[i]=1;
        }
        return res(1,1,dict,dp,target);
    }
};