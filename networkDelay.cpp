class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        vector<int>dist(n,1e9);
        dist[k-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        pq.push({0,k-1});
        while(!pq.empty()){
        auto temp=pq.top();
        pq.pop();
        int curDist=temp.first;
        int curNode=temp.second;
        for(auto it:adj[curNode]){
           int nxtNode=it.first;
           int nxtDist=it.second;
           if(curDist+nxtDist<dist[nxtNode]){
            dist[nxtNode]=curDist+nxtDist;
            pq.push({curDist+nxtDist,nxtNode});
           }
        }
        }
        int mx=INT_MIN;
        for(int i=0;i<n;i++){
          if(dist[i]==1e9)return -1;
          mx=max(mx,dist[i]);
        }
        return mx;
    }
};
