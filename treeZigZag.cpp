class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
      bool zigzag = true;
      stack<Node*> current;
      stack<Node*> next;
      vector<int> v;
      current.push(root);
      v.push_back(root->data);
      while(!current.empty()){
          Node* temp = current.top();
          
          current.pop();
          if(temp){
              if(zigzag){
                  if(temp->right){
                      next.push(temp->right);
                      Node* node = temp->right;
                      v.push_back(node->data);
                  }
                  if(temp->left){
                      next.push(temp->left); 
                       Node* node = temp->left;
                      v.push_back(node->data);
              }
              }else{
                  if(temp->left){
                      next.push(temp->left);
                       Node* node = temp->left;
                      v.push_back(node->data);
                  }
                  if(temp->right){
                      next.push(temp->right);
                       Node* node = temp->right;
                      v.push_back(node->data);
                  } 
          }
      } 
      if(current.empty()){
        zigzag = !zigzag;
        swap(current,next);
        
    }
      
    }
    
    return v;
}
};
