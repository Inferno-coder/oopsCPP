class Solution {
  public:
    int help(Node* root, int n){
            if(!root) return INT_MIN; 
            if(root->key > n)  return help(root->left,n); 
            else  return max(root->key, help(root->right,n)) ;
    }
    int findMaxForN(Node* root, int n) {
        int ans =  help(root, n);
        return (ans==INT_MIN)?-1:ans;
    }
};
