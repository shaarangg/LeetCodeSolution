class Solution {
public:
    int orangesRotting(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        queue<pair<int,int>> q;
        int rott=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j]==1) rott++;
                if(arr[i][j]==2){
                    q.push(make_pair(i,j));
                    rott++;
                } 
            }
        }
        int count=q.size();
        int days=0;
        while(!q.empty()){
            int k=q.size();
            bool push=false;
            while(k--){
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                if(i!=0 && arr[i-1][j]==1){
                    arr[i-1][j]=2;
                    q.push(make_pair(i-1,j));
                    push=true;
                    count++;
                }
                if(i!=n-1 && arr[i+1][j]==1){
                    arr[i+1][j]=2;
                    q.push(make_pair(i+1,j));
                    push=true;
                    count++;
                }
                if(j!=0 && arr[i][j-1]==1){
                    arr[i][j-1]=2;
                    q.push(make_pair(i,j-1));
                    push=true;
                    count++;
                }
                if(j!=m-1 && arr[i][j+1]==1){
                    arr[i][j+1]=2;
                    q.push(make_pair(i,j+1));
                    push=true;
                    count++;
                }
            }
            if(push) days++;
        }
        if(count==rott) return days;
        return -1;
    }
};