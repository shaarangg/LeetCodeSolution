class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count=0;
        for(auto i: t){
            if(i==s[count]) count++;
            if(count==s.length()) return true;
        }
        if(count==s.length()) return true;
        return false;
    }
};