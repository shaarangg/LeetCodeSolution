class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int colors[n];
        memset(colors,-1,sizeof(colors));
        unordered_map<int,bool> visited;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                queue<int> q;
                colors[i]=0;
                visited[i]=true;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    int col = ~colors[node];
                    for(auto j: graph[node]){
                        if(colors[j]==-1 || colors[j]==col){
                            colors[j]=col;
                            if(!visited[j]){
                                q.push(j);
                                visited[j]=true;
                            }
                        } else return false;
                    }
                }
            }
        }
        
        return true;
    }
};