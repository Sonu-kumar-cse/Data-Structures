#include<iostream>
using namespace std;

//function for linear search
int linearSearch(int arr[],int size,int data)
{

    for(int i=0;i<size;i++)
    {
        if(arr[i]==data)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int arr[]={3,6,53,456,34,56,74,6,6};
    int size=sizeof(arr)/sizeof(int);
    //some linear searching operation
    linearSearch(arr,size,34) == -1 ?cout<<"not found\n": cout<<"found\n";
    linearSearch(arr,size,2) == -1 ?cout<<"not found\n": cout<<"found\n";
    linearSearch(arr,size,3) == -1 ?cout<<"not found\n": cout<<"found\n";
    return 0;
}