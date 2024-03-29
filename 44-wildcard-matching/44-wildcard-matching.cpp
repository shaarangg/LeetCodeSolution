class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool> (n+1));
        for(int i=0; i<=m; i++) dp[i][0]=false;
        for(int i=0; i<=n; i++) dp[0][i]=false;
        for(int i=1; p[i-1]=='*' && i<=n; i++) dp[0][i]=true;
        dp[0][0]=true;
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]= dp[i][j-1] || dp[i-1][j-1] || dp[i-1][j];
                else dp[i][j]=false;
            }
        }
        return dp[m][n];
    }
};