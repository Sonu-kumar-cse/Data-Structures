#include<iostream>
using namespace std;

string rotateByOne(string s)
{
    char c=s[s.length()-1];
    for(int i=s.length()-1;i>0;i--)
    {
        s[i]=s[i-1];
    }
    s[0]=c;
    return s;
}

bool checkRotation(string a,string b)
{
    if(a.length()!=b.length()) return false;

    for(int i=0;i<a.length();i++)
    {
        if(a==b)
        {
            return true;
        }
        b=rotateByOne(b);
    }

    if(a==b) return true;
    return false;
}

int main()
{
    string a;
    cout<<"enter first string ";
    cin>>a;
    string b;
    cout<<"enter second string ";
    cin>>b;

    if(checkRotation(a,b))
    {
        cout<<"true";
    }
    else
    {
        cout<<"false";
    }

    return 0;
}