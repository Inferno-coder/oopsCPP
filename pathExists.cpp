class Solution {
public:
    void dfs(vector<int>adj[],int node,vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])dfs(adj,it,vis);
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>vis(n);
        dfs(adj,source,vis);
        if(vis[destination])return 1;
        return 0;
    }
};
