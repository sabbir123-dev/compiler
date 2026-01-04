//S → aSbb | T
//T → aT | bT | ε
//""
//"b"
//"abb"
//"abbb"
//"aabbbb"
//"bba"
#include<bits/stdc++.h>
using namespace std;
int main(){

string s;
cin>>s;
int a=0,b=0;
for(int i=0;i<s.length();i++)
{
    if(s[i]=='a'){
        a++;
    }
    else if(s[i]=='b'){
        b++;
    }
    else{
        cout<<"Not derived"<<endl;
        return 0;
    }
}
if(b>=2*a){
    cout<<"Derived"<<endl;
}
else{
    cout<<"Not derived"<<endl;
}
return 0;
}
