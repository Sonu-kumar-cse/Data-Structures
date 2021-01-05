#include<iostream>
using namespace std;

class SinglyLinkedList
{
    private:
        struct Node{
            int data;
            Node *next;
            Node(int d)
            {
                data=d;
                next= NULL;

            }
        };
        Node *head;
    
    public:
        
        SinglyLinkedList()
        {
            head=NULL;
        }

        void insert(int data)
        {
            Node *newnode=new Node(data);
            if(head==NULL)
            {
                head=newnode;
            }
            else
            {
                Node *temp=head;
                while(temp->next!=NULL)
                {
                    temp=temp->next;

                }
                temp->next=newnode;
            }
            
        }
        void displayAll()
        {
            if(head==NULL)
            {
                cout<<"list is empty";
            }
            else
            {
                Node *temp=head;
                while(temp!=NULL)
                {
                    cout<<temp->data<<" ";
                    temp=temp->next;
                }
            }
            
        }

};

int main()
{

    SinglyLinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.displayAll();
    return 0;
}