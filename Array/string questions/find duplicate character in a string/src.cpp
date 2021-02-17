#include<iostream>
using namespace std;

struct Node{
    char data;
    Node *next;
    Node(char a)
    {
        data=a;
        next=NULL;
    }
};

char getDuplicateCharacter(string s)
{
    char c;
    Node *head=NULL;
    for(int i=0;i<s.length();i++)
    {
        if(head==NULL)
        {
            head=new Node(s[i]);
        }else
        {
            Node *temp=head;
            
            while (true)
            {
                if(temp->data==s[i])
                {
                    return temp->data;
                }
                if(temp->next==NULL)
                {
                    temp->next=new Node(s[i]);
                    break;
                }
                temp=temp->next;
                
            }
        }
        
    }
    return '1';
}

int main()
{
    string s;
    cout<<"enter a string ";
    cin>>s;
    char c=getDuplicateCharacter(s);
    if(c=='1')
    {
        cout<<"no duplicate character";
    }
    else
    {
        cout<<c<<" is the duplicate character";
    }
    return 0;
}