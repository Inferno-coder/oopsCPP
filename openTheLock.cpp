class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>>q;
        unordered_set<string>st;
        for(int i=0;i<deadends.size();i++)st.insert(deadends[i]);
        q.push({"0000",0});
        while(!q.empty()){
           string temp=q.front().first;
           int step=q.front().second;
           q.pop();
           if(temp==target)return step;
           if(st.count(temp))continue;
           st.insert(temp);
           for (int i = 0; i < 4; i++) {
                string tempPlus = temp;
                tempPlus[i] = (tempPlus[i] == '9') ? '0' : tempPlus[i] + 1;
                q.push({tempPlus, step + 1});
                
                string tempMinus = temp;
                tempMinus[i] = (tempMinus[i] == '0') ? '9' : tempMinus[i] - 1;
                q.push({tempMinus, step + 1});
            }
        }
        return -1;
    }
};
