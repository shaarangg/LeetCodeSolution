class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n,vector<int> (n,0));
        for(int i=0; i<n; i++) dp[n-1][i] = matrix[n-1][i];
        for(int i = n-2; i>=0; i--){
            for(int j=0; j<n; j++){
                int diag_l=INT_MAX;
                int diag_r=INT_MAX;
                if(j!=0) diag_l = dp[i+1][j-1];
                if(j!=n-1) diag_r=dp[i+1][j+1];
                dp[i][j]=matrix[i][j]+min(diag_l,min(diag_r,dp[i+1][j]));
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<n; i++) ans=min(dp[0][i],ans);
        return ans;
    }
};