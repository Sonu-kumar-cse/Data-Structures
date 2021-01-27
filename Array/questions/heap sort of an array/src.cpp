#include<iostream>
using namespace std;


void insertIntoHeap(int heap[],int position)
{
    if(position<1)
    {   

        return;
    }
    int parent=position/2;
    if(parent<1)
    {
        return;
    }
    if(heap[position]>heap[parent])
    {
        int temp=heap[parent];
        heap[parent]=heap[position];
        heap[position]=temp;
        insertIntoHeap(heap,parent);
    }
}

void deleteFromHeap(int heap[])
{
    
}

int main()
{
    int arr[]={-1,5,36,67,4,3,35,7};
    int size=sizeof(arr)/sizeof(int);

    for(int i=1;i<size;i++)
    {
        insertIntoHeap(arr,i);
    }

    for(int i=1;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }


}