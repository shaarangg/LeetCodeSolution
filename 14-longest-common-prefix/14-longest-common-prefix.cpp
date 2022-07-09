class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
        int n = strs.size();
        if(n==1) return strs[0];
        if(strs[0].length()==0) return "";
        char check;
        while(true){
            check=strs[0][i];
            for(int j=1; j<n; j++){
                if(i>=strs[j].length() || check!=strs[j][i]) return strs[j].substr(0,i);
            }
            i++;
        }
    }
};