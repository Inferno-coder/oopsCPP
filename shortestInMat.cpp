class Solution {
public:
    int dir[5] = {0, -1, 0, 1, 0};

    void dfs(int row, int col, vector<vector<int>>& mat, vector<vector<int>>& vis, int totRow, int totCol, int& mini, int sum) {
        if (row < 0 || row >= totRow || col < 0 || col >= totCol || mat[row][col] == 0 || vis[row][col])
            return;

        if (col == totCol - 1) {
            if(mat[row][col]==1){
            mini = min(mini, sum);
            }
            return;
        }

        vis[row][col] = 1;

        for (int i = 0; i < 4; i++) {
            int newr = row + dir[i];
            int newc = col + dir[i + 1];

            if (newr >= 0 && newr < totRow && newc >= 0 && newc < totCol && mat[newr][newc] == 0)
                return;
        }

        dfs(row - 1, col, mat, vis, totRow, totCol, mini, sum + 1);
        dfs(row + 1, col, mat, vis, totRow, totCol, mini, sum + 1);
        dfs(row, col - 1, mat, vis, totRow, totCol, mini, sum + 1);
        dfs(row, col + 1, mat, vis, totRow, totCol, mini, sum + 1);

        vis[row][col] = 0;
    }

    int findShortestPath(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        int mini = INT_MAX;
        vector<vector<int>> vis(row, vector<int>(col, 0));

        for (int i = 0; i < row; i++) {
            if (mat[i][0] == 1) {
                dfs(i, 0, mat, vis, row, col, mini, 1);
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
