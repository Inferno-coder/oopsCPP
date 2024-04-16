/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
      if (depth == 1) {
            TreeNode* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        int d = 1;
        
        while (!q.empty()) {
            int sz = q.size();
            
            for (int i = 0; i < sz; i++) {
                TreeNode* temp = q.front();
                q.pop();
                
                if (d == depth - 1) {
                    TreeNode* l = temp->left;
                    temp->left = new TreeNode(val);
                    temp->left->left = l;
                    
                    TreeNode* r = temp->right;
                    temp->right = new TreeNode(val);
                    temp->right->right = r;
                } else {
                    if (temp->left) q.push(temp->left);
                    if (temp->right) q.push(temp->right);
                }
            }
            
            if (d == depth - 1) break; // Stop processing further levels
            d++;
        }
        
        return root;
    }
};
