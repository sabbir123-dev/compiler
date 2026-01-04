#include<bits/stdc++.h>
#include<string.h>
#define endl '\n'
using namespace std;
int main(){
//S → aSbb | abb
//or
//s->aSAb|ε
//A->b
string s;
cin>>s;
if(s.empty()){
    cout<<"Derived"<<endl;
    return 0;
}
int a=0,b=0,i=0;
while(i<s.length()&&s[i]=='a'){
    a++;
    i++;
}
while(i<s.length()&&s[i]=='b'){
    b++;
    i++;
}
if(i==s.length()&& b==2*a){
    cout<<"Derived"<<endl;
}
else{
    cout<<"Not Derived"<<endl;
}
return 0;
}
