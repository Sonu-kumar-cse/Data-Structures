#include<iostream>
using namespace std;

int main()
{
    string s;
    cout<<"enter a number string ";
    cin>>s;
    string res="";
    char num=s[0];
    int count=1;

    for(int i=1;i<s.length();i++)
    {
        if(s[i]==num)
        {
            count++;
        }
        else
        {
            res+=count+'0';
            res+=num;
            num=s[i];
            count=1;
        }
    }
    res+=count+'0';
    res+=num;
    cout<<res;
    return 0;
}