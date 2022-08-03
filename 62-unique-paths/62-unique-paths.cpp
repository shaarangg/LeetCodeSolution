class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                if(i==0 || j==0) dp[i][j]=0;
                else if(i==1 || j==1) dp[i][j]=1;
            }
        }
        for(int i = 2; i<=m; i++){
            for(int j=2; j<=n;j++){
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
        
};