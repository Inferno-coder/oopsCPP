class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
         int n=grid.size();
         int m=grid[0].size();
         int dir[5]={0,-1,0,1,0};
         int res=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    for(int k=0;k<4;k++){
                        int newR=i+dir[k];
                        int newC=j+dir[k+1];
                        if(newR<0 || newR>=n || newC<0 || newC>=m || grid[newR][newC]==0)res++;
                    }
                }
            }
         }
         return res;
    }
};
