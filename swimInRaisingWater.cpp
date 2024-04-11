class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet dsu(n*n);
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                vec.push_back({grid[i][j],i*n+j});
            }
        }
        sort(vec.begin(),vec.end());
        int dir[5]={0,-1,0,1,0};
        for(auto it:vec){
            int val=it.first;
            int node=it.second;
            int x=node/n,y=node%n;
            for(int i=0;i<4;i++){
                int newX=x+dir[i];
                int newY=y+dir[i+1];
                if(newX>=0 &&  newY>=0 && newX<n && newY<n && grid[newX][newY]<grid[x][y]){
                    dsu.unionBySize(x*n+y,newX*n+newY);
                }
                if(dsu.findUPar(0)==dsu.findUPar(n*n-1))return val;
            }
        }
        return -1;
    }
};
