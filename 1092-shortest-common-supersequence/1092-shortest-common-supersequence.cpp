class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        vector<vector<string>> dp(m+1,vector<string> (n+1,""));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+str1[i-1];
                else{
                    if(dp[i-1][j].length()>dp[i][j-1].length()) dp[i][j]=dp[i-1][j];
                    else dp[i][j]=dp[i][j-1];
                }
            }
        }
        string str=dp[m][n];
        cout<<str;
        int l = str.length();
        string ans="";
        int idx=0;
        int i=0,j=0;
        while(idx<l){
            while(i<m && str1[i]!=str[idx]){
                ans+=str1[i];
                i++;
            } 
            while(j<n && str2[j]!=str[idx]){
                ans+=str2[j];
                j++;
            }
            ans+=str[idx];
            idx++;
            i++;
            j++;
        }
        while(i<m) ans+=str1[i++];
        while(j<n) ans+=str2[j++];
        return ans;
    }
};