class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                if(i==1) dp[i][j]=grid[i-1][j-1]+dp[i][j-1];
                else if(j==1) dp[i][j]=grid[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=grid[i-1][j-1]+min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};