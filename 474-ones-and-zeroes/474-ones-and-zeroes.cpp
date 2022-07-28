class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l = strs.size();
        vector<vector<vector<int>>> dp(l+1,vector<vector<int>>(m+1,vector<int> (n+1)));
        for(int i=0; i<=m; i++){
            for(int j=0; j<=n; j++){
                dp[0][i][j]=0;
            }
        }
        for(int i=1; i<=l; i++){
            string s = strs[i-1];
            int zero = count(s.begin(),s.end(),'0');
            int one = count(s.begin(),s.end(),'1');
            for(int j=0; j<=m; j++){
                for(int k=0; k<=n; k++){
                    if(zero<=j && one<=k){
                        dp[i][j][k]=max(1+dp[i-1][j-zero][k-one], dp[i-1][j][k]);
                    } else{
                        dp[i][j][k]=dp[i-1][j][k];
                    }
                }
            }
        }
        return dp[l][m][n];
    }
};