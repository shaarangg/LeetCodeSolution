class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> balls;
        for(int i=0; i<n; i++){
            balls.push_back({0,i});
        }
        vector<int> ans(n);
        bool flag=true;
        while(flag==true){
            flag=false;
            for(int idx=0; idx<n; idx++){
                int i = balls[idx].first;
                int j = balls[idx].second;
                if(grid[i][j]==1){
                    if(j==n-1) ans[idx]=-1;
                    else if(grid[i][j+1]==-1) ans[idx]=-1;
                    else if(i==m-1) ans[idx]=j+1;
                    else{
                        balls[idx].first+=1;
                        balls[idx].second+=1;
                        flag=true;
                    }
                }
                else{
                    if(j==0) ans[idx]=-1;
                    else if(grid[i][j-1]==1) ans[idx]=-1;
                    else if(i==m-1) ans[idx]=j-1;
                    else{
                        balls[idx].first+=1;
                        balls[idx].second-=1;
                        flag=true;
                    }
                }
            }
        }
        return ans;
    }
};