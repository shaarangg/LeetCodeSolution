class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<int> u;
        int n = s.length();
        int l =0;
        int r=0;
        int len=0,mL=0;
        for(int i=0; i<n; i++){
            if(u.find(s[i])==u.end()){
                u.insert(s[i]);
                r++;
            }
            else{
                for(int j=l; j<r; j++){
                    if(u.find(s[j])==u.find(s[i])){
                        u.erase(s[j]);
                        l++;
                        break;    
                    } 
                    u.erase(s[j]);
                    l++;
                }
                u.insert(s[i]);
                r++;
            }
            len = r-l;
            // cout<<len<<" ";
            mL = max(mL,len);
        }
        return mL;
    }
};