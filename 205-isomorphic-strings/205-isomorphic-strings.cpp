class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()==t.length()){
            unordered_map<char,char> dict1;
            unordered_map<char,char> dict2;
            for(int i=0; i<s.length(); i++){
                if(dict1.find(s[i])==dict1.end() || dict1[s[i]]==t[i]){
                    if(dict2.find(t[i])==dict2.end() || dict2[t[i]]==s[i]){
                        dict1[s[i]]=t[i];
                        dict2[t[i]]=s[i];
                    }
                    else return false;
                }
                else return false;
            }
            return true;
        }
        return false;
    }
};