class Solution {
public:
    bool check(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int n = grid1.size();
        int m = grid1[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid1[i][j]!=grid2[i][j]) return false;
            }
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count=0;
        vector<vector<int>> gridcp(n,vector<int>(m));
        gridcp=grid;
        while(true){
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(grid[i][j]==1){
                         if(i!=0 && grid[i-1][j]==2 || i!=n-1 && grid[i+1][j]==2 || j!=0 && grid[i][j-1]==2 || j!=m-1 && grid[i][j+1]==2){
                             gridcp[i][j]=2;
                         }
                    }
                }
            }
            if(check(grid,gridcp)) break;
            grid = gridcp;
            count++;
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return count;
    }
};