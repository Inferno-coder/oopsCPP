class Solution {
public:
     string smallestFromLeaf(TreeNode* root) {
        if (!root) return "";
        string current = "";
        string smallest = "|"; 
        dfs(root, current, smallest);
        return smallest;
    }
    
    void dfs(TreeNode* node, string current, string& smallest) {
        
        if (!node->left && !node->right) {
            current += static_cast<char>('a' + node->val); 
            reverse(current.begin(), current.end());
            if (current < smallest) smallest = current;
            return;
        }
        current += static_cast<char>('a' + node->val); 
        if (node->left) dfs(node->left, current, smallest);
        if (node->right) dfs(node->right, current, smallest);
    }
};
