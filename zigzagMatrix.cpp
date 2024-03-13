class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         int n=mat.size();
         int index=0;
         vector<int>ans(n*n);
         int i=0,j=0;
         bool up=1;
         
         while(i<n && j<n){
             
             if(up){
                 while(i>0 && j< n-1){
                     ans[index]=mat[i][j];
                     i--;j++;
                     index++;
                 }
                 ans[index++]=mat[i][j];
                 if(j==n-1){
                     i++;
                 }
                 else j++;
                 
             }
             else{
                  while(i< n-1 && j>0){
                     ans[index]=mat[i][j];
                     i++;j--;
                     index++;
                 }
                 ans[index++]=mat[i][j];
                 if(i==n-1){
                     j++;
                 }
                 else i++;
             }
             up=!up;
         }
         
         return ans;
    }
};
