#include<iostream>
using namespace std;

class Queue{

    private:
        int *queue;
        int size;
        int front, rear;
    public:
        Queue(int data)
        {
            queue=new int[data];
            size=data;
            front=rear=-1;
        }

        void enQueue(int data)
        {
            if(rear==size-1)
            {
                cout<<"queue is full";
            }            
            else if(rear==-1)
            {
                front=0;
                rear=0;
                queue[rear]=data;
            }
            else
            {
                rear++;
                queue[rear]=data;
            }
            
        }
        void deQueue()
        {
            if(front==-1)
            {
                cout<<"queue is empty";

            }
            else if(front==rear)
            {
                front=rear=-1;
            }
            else
            {
                front++;
            }
            
        }

        int getFront()
        {
            if(front==-1)
                return -1;
            return queue[front];
        }
    
};


int main()
{
    Queue q(5);
    q.enQueue(23);
    q.enQueue(22);
    q.enQueue(231);
    q.enQueue(232);
    q.deQueue();
    cout<<q.getFront();
}