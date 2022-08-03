class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        for(int i=1; i<=m && obstacleGrid[i-1][0]==0; i++) dp[i][1]=1;
        for(int i=1; i<=n && obstacleGrid[0][i-1]==0; i++) dp[1][i]=1;
        for(int i=2; i<=m; i++){
            for(int j=2; j<=n; j++){
                if(obstacleGrid[i-1][j-1]==0) dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
        return dp[m][n];
    }
};