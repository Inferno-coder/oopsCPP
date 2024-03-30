   int minValue(Node* root) {
        // Code here
        int mini=99999;
        while(root){
            mini=min(root->data,mini);
            root=root->left;
        }
        return mini;
    }
