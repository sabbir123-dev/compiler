//S → aT
//T → bT | ε
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;

    if(s.empty()||s[0]!='a')
    {
        cout<<"Not derived"<<endl;
        return 0;
    }

    int i=0;
    if(s[i]=='a')
    {
        i++;
    }
    while(i<s.length()&&s[i]=='b')
    {
        i++;
    }
    if(i==s.length())
    {
        cout<<"Derived"<<endl;
    }
    else
    {
        cout<<"Not derived"<<endl;
    }
    return 0;

}
