class Solution {
public:
    string reverseWords(string s) {
        int len = s.length();
        if(len==0) return s;
        string ans="";
        string temp = "";
        for(int i=0; i<len; i++){
            if(s[i]==' '){
                if(temp=="") continue;
                if(ans=="") ans = temp;
                else ans = temp + " " + ans;
                temp="";
            }
            else temp+=s[i];
        }
        if(temp!=" ") ans = temp+" "+ans;
        len = ans.length();
        if(ans[0]==' ') return ans.substr(1,len-1);
        if(ans[len-1]==' ') return ans.substr(0,len-1);
        return ans;
    }
};