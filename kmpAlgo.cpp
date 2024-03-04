class KMP{
public:
	vector<int>computeLps(string &pattern){
     int n=pattern.size();
     vector<int>lps(n);
     int len=0;
     lps[0]=0;
     int i=1;
     while(i<n){
     if(pattern[i]==pattern[len]){
     len++;
     lps[i]=len;
     i++;
     }
     else{
     if(len!=0){
     len=lps[len-1];
     }
     else{
      lps[i]=0;
      i++;
     } 
     }
     }
     return lps;
	}	
  
   void findMatch(string text,string pattern){
     int m=pattern.length();
     int n=text.length();
     vector<int>lps=computeLps(pattern);
     int i=0,j=0;
     while(i<n){
     if(pattern[j]==text[i]){
      i++;j++;
     }
     if(j==m){
       cout<<"pattern found in "<<i-j<<endl;
       j=lps[j-1];
     }
     else if(i<n && pattern[j]!=text[i]){
      if(j!=0){
        j=lps[j-1];
      }
      else{	
      	i++;
      }
     }
     }
   }
};
