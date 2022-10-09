class Solution {
public:
    bool dfs(int node, unordered_map<int,vector<int>> &adj_list, unordered_map<int,bool> &vis, unordered_map<int,bool> &recS){
        vis[node]=true;
        recS[node]=true;
        for(auto i: adj_list[node]){
            if(!vis[i]){
                if(dfs(i,adj_list,vis,recS)) return true;
            }
            else if(recS[i]) return true;
        }
        recS[node]= false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj_list;
        for(auto i: prerequisites){
            adj_list[i[0]].push_back(i[1]);
        }
        unordered_map<int,bool> vis;
        unordered_map<int,bool> recS;
        for(int i=0; i<numCourses; i++){
            if(!vis[i]){
                if(dfs(i,adj_list,vis,recS)) return false;
            }    
        }
        return true;
    }
};