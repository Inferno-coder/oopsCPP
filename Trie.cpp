#include <bits/stdc++.h>
using namespace std;
class Node{
public:
  Node* links[26];
  bool flag=false;
  
  bool containsKey(char ch){
      return links[ch-'a']!=NULL;
  }
};

class trieNode{
public:
 Node* root=new Node();
 
 void insert(string str){
     Node* temp=root;
  for(int i=0;i<str.length();i++){
      char ch=str[i];
      if(!temp->containsKey(ch)){
       temp->links[ch-'a']=new Node();
      }
      temp=temp->links[ch-'a'];
  }
  temp->flag=true;
 }
 
 bool search(string str){
     Node* temp=root;
     for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(!temp->containsKey(ch))return false;
        temp=temp->links[ch-'a'];
     }
     if(temp->flag==false)return false;
     return true;
 }
 
 bool prefix(string str){
       Node* temp=root;
     for(int i=0;i<str.length();i++){
        char ch=str[i];
        if(!temp->containsKey(ch))return false;
        temp=temp->links[ch-'a'];
     }
     return true;
 }
};

int main()
{
    trieNode t;
    t.insert("pradeep");
    cout<<t.prefix("pra");
    return 0;
}
