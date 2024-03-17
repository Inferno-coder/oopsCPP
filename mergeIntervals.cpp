class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>res;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        int cur_i=intervals[0][0];
        int cur_j=intervals[0][1];
        int sz=intervals.size();
        for(int j=1;j<sz;j++){
            if(intervals[j][0]<=cur_j){
                cur_j=max(cur_j,intervals[j][1]);
            }
            else {
                res.push_back({cur_i,cur_j});
                cur_i=intervals[j][0];
                cur_j=intervals[j][1];
            }
        }
        res.push_back({cur_i,cur_j});
        return res;
    }
};
