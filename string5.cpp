//S → aSA | bSB | ε
//A → b
//B → a
//"ab" (1 a, 1 b)
//"ba" (1 b, 1 a)
//"aabb" (2 a's, 2 b's)
//"abab" (2 a's, 2 b's)
//"baabba" (3 a's, 3 b's)

#include<bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;

if(s.empty()){
    cout<<"Derived"<<endl;
    return 0;
}

int a=0,b=0;
for(int i=0;i<s.length();i++){
    if(s[i]=='a'){
        a++;
    }
    else if(s[i]=='b'){
        b++;
    }
    else{
      cout<<"Not Derived"<<endl;
      return 0;
    }

}
if(a==b){
    cout<<"Derived"<<endl;
}
else{
    cout<<"Not derived"<<endl;
}
return 0;

}
