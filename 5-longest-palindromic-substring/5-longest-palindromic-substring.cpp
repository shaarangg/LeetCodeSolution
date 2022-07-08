class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int ans=0;
        int start=0;
        for(int i=0; i<n; i++){
            int l =i, r=i;
            while(l>=0 && r<n){
                if(s[l]!=s[r]) break;
                if(r-l+1 > ans){
                    ans = r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
            l=i,r=i+1;
            while(l>=0 && r<n){
                if(s[l]!=s[r]) break;
                if(r-l+1 > ans){
                    ans = r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,ans);
    }
};