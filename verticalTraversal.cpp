class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //map<vertical,map<level,multiset(...)>>
        map<int,map<int,multiset<int>>>nodes;
        //queue-> nodeValue,vertical,level
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp=q.front();
            int val=temp.first->val;
            int vertical=temp.second.first;
            int level=temp.second.second;
            q.pop();
            nodes[vertical][level].insert(val);
            if(temp.first->left){
                q.push({temp.first->left,{vertical-1,level+1}});
            }
            if(temp.first->right){
                q.push({temp.first->right,{vertical+1,level+1}});
            }
        }
        vector<vector<int>>res;
        for(auto it:nodes){
            vector<int>temp;
            for(auto t:it.second){
             temp.insert(temp.end(),t.second.begin(),t.second.end());
            }
            res.push_back(temp);
        }
        return res;
    }
};
