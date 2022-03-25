class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r, vector<int>(c,0));
        int a=0,b=0,m=mat.size(),n=mat[0].size();
        if(m*n!=r*c) return mat;
        for(int i=0;i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(b==c){
                    b=0;
                    a++;
                }
                ans[a][b]=mat[i][j];
                b++;
            }
        }
        return ans;
    }
};