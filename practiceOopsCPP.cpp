#include <iostream>
using namespace std;
template<class t>
void swapping(t &a,t &b){
    t temp=a;
    a=b;
    b=temp;
}
int main()
{
    char ch1='a';
    char ch2='b';
    int a =1;
    int b=2;
    swapping(ch1,ch2);
    swapping(a,b);
    cout<<ch1<<" "<<ch2<<endl;
    cout<<a<<" "<<b<<endl;
    return 0;
}
