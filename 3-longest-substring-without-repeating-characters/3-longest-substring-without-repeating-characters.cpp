class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> u;
        int n = s.length();
        int ml=0;
        int l=0,r=0;
        for(int i=0; i<n; i++){
            if(u.find(s[i])==u.end()){
                u.insert(s[i]);
            } else{
                while(s[l]!=s[i]){
                    u.erase(s[l]);
                    l++;
                }
                l++;
            }
            r++;
            // cout<<l<<" "<<r<<endl;
            ml=max(r-l,ml);
        }
        return ml;
    }
};