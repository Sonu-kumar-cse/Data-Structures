#include<iostream>
using namespace std;

class Queue{

    private:
        struct Node
        {
            int data;
            Node *next;
            Node(int x)
            {
                data=x;
                next=NULL;
            }
        };
        Node *front;
    
    public:
        Queue()
        {
            front=NULL;
        }
        void enQueue(int data)
        {
            if(front==NULL)
            {
                front=new Node(data);
            }
            else
            {
                Node *temp=front;
                while(temp->next!=NULL)
                {
                    temp=temp->next;
                }
                temp->next=new Node(data);
            }
            
        }

        void dequeue()
        {
            if(front==NULL)
            {
                cout<<"queue is empty";
            }
            else
            {
                front=front->next;
            }
            
        }

        int getFront()
        {
            if(front==NULL)
            {
                return -1;
            }
            return front->data;
        }

};

int main()
{
    
    Queue q;
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.enQueue(50);
    q.dequeue();
    cout<<q.getFront();
    return 0;
}