#include<iostream>
using namespace std;

class Stack{

    private:
        int *stack;
        int top;
        int size;
    
    public:

        Stack(int data)
        {
            stack=new int[data];
            size=data;
            top=-1;
        }

        void push(int data)
        {
            if(top==size-1)
            {
                cout<<"stack overflow";
            }
            else
            {
                top++;
                stack[top]=data;
            }
            
        }
        
        void pop()
        {
            if(top==-1)
            {
                cout<<"stack underflow";
            }
            else
            {
                cout<<stack[top]<<" poped out";
                top--;
            }
            
        }


};

int main()
{

    Stack s(10);

    s.push(12);
    s.push(13);
    s.push(14);
    s.push(15);

    s.pop();

    return 0;
}