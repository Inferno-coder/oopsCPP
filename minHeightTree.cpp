#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        queue<int> q;
        if (n == 1) return {0};
        vector<int> inDegree(n, 0);
        
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            inDegree[it[0]]++;
            inDegree[it[1]]++;
        }
        
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 1) q.push(i);
        }
        
        while (n > 2) {
            int q_size = q.size();
            n -= q_size;
            for (int i = 0; i < q_size; i++) {
                int temp = q.front();
                q.pop();
                
                for (auto neighbor : adj[temp]) {
                    inDegree[neighbor]--;
                    if (inDegree[neighbor] == 1) {
                        q.push(neighbor);
                    } 
                }
            }
        }
        
        vector<int> res;
        while (!q.empty()) {
            res.push_back(q.front());
            q.pop();
        }
        
        return res;
    }
};
