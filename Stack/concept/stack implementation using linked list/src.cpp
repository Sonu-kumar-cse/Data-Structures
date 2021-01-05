#include<iostream>
using namespace std;

class Stack
{
    private:
        struct Node
        {
            int data;
            Node *next;
            Node(int x)
            {
                data =x;
                next=NULL;
            }
        };

        Node *top;

    public:
        Stack()
        {
            top=NULL;
        }
        
        void push(int data)
        {
            if(top==NULL)
            {
                top=new Node(data);

            }
            else
            {
                Node *newnode= new Node(data);
                newnode->next=top;
                top=newnode;
            }
            
        }

        void pop()
        {
            if(top==NULL)
            {
                cout<<"stack underflow";
            }
            else
            {
                cout<<top->data<<" poped out";
                top=top->next;
            }
            
        }

};

int main()
{

    Stack s;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);

    s.pop();

    return 0;
}