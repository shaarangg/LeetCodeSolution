class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==1) return ans;   
        temp.push_back(1);
        ans.push_back(temp);
        if(numRows==2) return ans;
        for(int i=3; i<=numRows; i++){
            vector<int> t(i);
            for(int j=0; j<i; j++){
                if(j==0 || j==i-1) t[j]=1;
                else t[j] = ans[i-2][j-1] + ans[i-2][j];
            }
            ans.push_back(t);
        }
        return ans;
    }
};