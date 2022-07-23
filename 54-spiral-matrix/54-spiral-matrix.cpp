class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r[]= {0,1,0,-1};
        int c[]={1,0,-1,0};
        int n =matrix.size();
        int m = matrix[0].size();
        bool checkMatrix[n][m];
        memset(checkMatrix,false,sizeof(checkMatrix));
        int mv=0;
        vector<int> ans;
        int i=0,j=0;
        for(int idx=0; idx<m*n; idx++){
            ans.push_back(matrix[i][j]);
            checkMatrix[i][j]=true;
            int i_new=i+r[mv];
            int j_new=j+c[mv];
            if(i_new>=0 && i_new<n && j_new>=0 && j_new<m && checkMatrix[i_new][j_new]==false){
                i=i_new;
                j=j_new;
            } else{
                mv = (mv+1)%4;
                i = i+r[mv];
                j = j+c[mv];
            }
        }
        return ans;
    }
};