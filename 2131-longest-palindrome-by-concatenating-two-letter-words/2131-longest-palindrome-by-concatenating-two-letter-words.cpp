class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> dict;
        int ans=0;
        for(int i=0; i<words.size(); i++) dict[words[i]]++;
        bool flag=false;
        for(auto i: dict){
            string x = i.first;
            reverse(x.begin(),x.end());
            if(i.second>0){
                if(i.first!=x && dict.find(x)!=dict.end()){
                    int m = min(i.second,dict[x]);
                    ans+=m*4;
                    dict[x]-=m;
                    dict[i.first]-=m;
                }
                if(i.first==x){
                    if(i.second%2==0){
                        ans+=i.second*2;
                        i.second=0;
                    }
                    else if(!flag){
                        ans+=i.second*2;
                        i.second=0;
                        flag=true;
                    }
                    else if(i.second>1){
                        ans+=(i.second-1)*2;
                        i.second=1;
                    }
                }
            }
        }
        return ans;
    }
};