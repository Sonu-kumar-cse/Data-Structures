#include<iostream>
using namespace std;

//basic node for making link
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

//fucntion for getting index of a data 
int getIndex(int data)
{
    //in this implementation we use a hash of size 20
    return data%20;
}

//function for creating a hash
void createHash(Node *hash[], int arr[], int n, int hashSize)
{
    for(int i=0;i<n;i++)
    {
        int index=getIndex(arr[i]);
        if(hash[index]==NULL)
        {
            hash[index]=new Node(arr[i]);
        }
        else
        {
            Node *temp=hash[index];
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new Node(arr[i]);

        }
        
    }

}

//function for searching a data
void searchData(int data,Node *hash[])
{

    int index=getIndex(data);
    Node *temp=hash[index];
    while(temp!=NULL)
    {
        if(temp->data==data)
        {
            cout<<"data found"<<endl;
            return;
        }
        temp=temp->next;
    }
    cout<<"not found"<<endl;
    return;

}

int main()
{
    //simple array
    int arr[]={23,4,5,6,3,44,6,7,8};
    int n=sizeof(arr)/sizeof(int);

    //hash of size 20
    Node *hash[20];
    const int HASH_SIZE=20;
    
    //filling NULL in the whole hash array
    for(int i=0;i<HASH_SIZE;i++)
    {
        hash[i]=NULL;
    } 

    //calling create function for filling array data in the hash
    createHash(hash,arr,n,HASH_SIZE);

    //searching some data
    searchData(23,hash);
    searchData(223,hash);
    searchData(3,hash);
    searchData(4,hash);
    searchData(44,hash);
    return 0;
}