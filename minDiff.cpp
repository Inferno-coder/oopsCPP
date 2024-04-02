 void solve(Node *root,int &prev,int &mn){
        if(!root)return;
        solve(root->left,prev,mn);
        if(prev!=-1)mn=min(mn,abs(root->data-prev));
        prev=root->data;
        solve(root->right,prev,mn);
    }
    int absolute_diff(Node *root)
    {
        //Your code here
        int prev=-1;
        int mn=INT_MAX;
        solve(root,prev,mn);
        return mn;
    }
