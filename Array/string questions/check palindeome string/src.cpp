#include<iostream>
using namespace std;

bool checkPalindrome(string s)
{
    for(int i=0;i<s.length()/2;i++)
    {
        if(s[i]!=s[s.length()-1-i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string s;
    cout<<"enter string : ";
    cin>>s;
    if(checkPalindrome(s))
    {
        cout<<"string is palindrome";
    }
    else{
        cout<<"string is not palindrome";
    }
    return 0;
}