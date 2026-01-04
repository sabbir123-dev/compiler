//S → aS | A
//A → bA | b
#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    if(s.empty())
    {

        cout<<"Not derived"<<endl;
        return 0;
    }
    int i=0;
    while(i<s.length()&&s[i]=='a')
    {
        i++;
    }
    if(i>=s.length()|| s[i]!='b')
    {
        cout<<"Not derived"<<endl;
        return 0;
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
        cout<<"Not Derived"<<endl;
    }
    return 0;

}

