#include<iostream>
using namespace std;

int main()
{
    string s;
    cout<<"enter a string : ";
    cin>>s;

    for(int i=0;i<s.length()/2;i++)
    {
        char temp=s[i];
        s[i]=s[s.length()-1-i];
        s[s.length()-1-i]=temp;
    }
    cout<<"string after reversing : "<<s;


    return 0;
}