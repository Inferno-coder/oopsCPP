class Node{
public:
Node* links[2];
      bool containsKey(int num){
        return links[num]!=NULL;    
      }
};

class Trie{
private:
   Node* root;
public:
    Trie(){
    root=new Node();
    }
     
      void insert(int num){
          Node* temp=root;
          for(int i=31;i>=0;i--){
              int bit=(num>>i)&1;
              if(!temp->containsKey(bit)){
                  temp->links[bit]=new Node();
              }
              temp=temp->links[bit];
          }
      }
      int getMax(int num){
          int maxi=0;
          Node* temp=root;
          for(int i=31;i>=0;i--){
            int bit=(num>>i)&1;
            if(temp->containsKey(1-bit)){
                maxi=maxi|(1<<i);
                temp=temp->links[(1-bit)];
            }
            else{
                 temp=temp->links[(bit)];
            }
          }
          return maxi;
      }
};
