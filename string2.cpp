//S → aSb | ab
#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
int i=0,a=0,b=0;
while(i<s.length()&&s[i]=='a'){
    a++;
    i++;
}
while(i<s.length()&&s[i]=='b'){
    b++;
    i++;
}
if(i==s.length()&&a==b){
    cout<<"Derived"<<endl;
}
else{
    cout<<"Not Derived"<<endl;
}

}
