//User function Template for C++

/*// A Tree node
struct Node
{
	int data;
	struct Node *left, *right;
};*/


class Solution
{
    public:
    vector<int>kthCA(Node *root,vector<int>&ans,int x,int y)
    {
        if(root==NULL)return ans;
        int cur=root->data;
        
        if(cur<x&&cur<y)
        {
            ans.push_back(cur);
            return kthCA(root->right,ans,x,y);
        }
        if(cur>x&&cur>y)
        {
            ans.push_back(cur);
            return kthCA(root->left,ans,x,y);
        }
        ans.push_back(cur);
        return ans;
    }
    /*You are required to complete below function */
    int kthCommonAncestor(Node *root, int k,int x, int y)
    {
        // your code goes here
        vector<int>ans;
        kthCA(root,ans,x,y);
        int n=ans.size();
        if((n<k))return -1;
        int a=ans[n-k];
        return a;
    }
};
