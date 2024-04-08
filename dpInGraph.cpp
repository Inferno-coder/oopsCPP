class Solution {
public:
    long long mod = 1e9 + 7;
    long long countPaths(int n, vector<vector<int>>& roads) {
        vector<long long> ways(n, 0), dist(n, LONG_MAX);
        vector<pair<int, int>> adj[n];
        int sz = roads.size();
        for (int i = 0; i < sz; i++) {
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pair<long long, iant>, vector<pair<long long, int>>, greater<>>pq;
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int curNode = temp.second;
            long long curDist = temp.first;
            for (auto it : adj[curNode]) {
                int nxtNode = it.first;
                long long nxtDist = it.second;
                if (curDist + nxtDist < dist[nxtNode]) {
                    dist[nxtNode] = curDist + nxtDist;
                    pq.push({dist[nxtNode], nxtNode});
                    ways[nxtNode] = ways[curNode] % mod;
                }
                else if (curDist + nxtDist == dist[nxtNode]) {
                    ways[nxtNode] = (ways[curNode] + ways[nxtNode]) % mod;
                }
            }
        }
        return ways[n - 1] % mod;
    }
};
