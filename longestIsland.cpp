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
    int largestIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
        DisjointSet dsu(n*m);
       int dir[5]={0,-1,0,1,0};
       int maxOnes=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
           if(grid[i][j]==1){
            maxOnes++;
               for(int k=0;k<4;k++){
                int newX=i+dir[k];
                int newY=j+dir[k+1];
                if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1){
                    dsu.unionBySize((i*m+j),(newX*m+newY));
                }
               }
           }
        }
       }
    if(maxOnes==n*n)return maxOnes;
    int res=0;
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==0){
                set<int>st;
                for(int k=0;k<4;k++){
                   int newX=i+dir[k];
                   int newY=j+dir[k+1];
                    if(newX>=0 && newY>=0 && newX<n && newY<m && grid[newX][newY]==1){
                    st.insert(dsu.findUPar(newX*m+newY));
                    }
                }cout<<endl;
                int c=0;
               for(auto it:st){
                c+=dsu.size[it];
               }
               c++;
              res=max(res,c);
            }
        }
       }
    return res;
    }
};

