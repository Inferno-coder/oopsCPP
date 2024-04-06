class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open=0,close=0;
        string res="";
        for(int i=0;i<s.length();i++){
         if(s[i]=='('){
          res+='(';
          open++;
         }
         else if(s[i]==')'){
          if(open<=0)continue;
          else {
            res+=')';
            close++;
            if(open>0)open--;
          }
         }
         else res+=s[i];
        }
        string ans="";
        for(int i=res.length()-1;i>=0;i--){
        if(res[i]=='(' && open>0){
         open--;continue;
        }
        else{
           ans+=res[i]; 
        }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
