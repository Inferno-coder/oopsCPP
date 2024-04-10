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
vector<int> numberOfIslandII(int n, int m, vector<vector<int>>& queries, int q)
{
    // Write your code here.
    int dir[5]={0,-1,0,1,0};
    vector<int>vis(n*m,0);
    vector<int>res;
    int com=0;
    DisjointSet dsu(n*m);
    for (auto it : queries) {
      int node=(it[0]*m)+it[1];
      vis[node]=1;
      com++;
      for (int i = 0; i < 4; i++) {
        int newX=it[0]+dir[i];
        int newY=it[1]+dir[i+1];
        if(newX >= 0 && newX < n && newY >= 0 && newY < m && vis[(newX*m+newY)]){
          if (dsu.findUPar(node) != dsu.findUPar((newX * m + newY))) {
            dsu.unionBySize(node, newX * m + newY);
            com--;
          }
        }
      }
    res.push_back(com);
    }
    return res;
}
