#include<iostream>
#include<math.h>
using namespace std;

// jump sort works only on sorted arrays
//it's not working properly fix it
int jumpSearch(int arr[],int size,int data)
{
    int jump=sqrt(size);
    
    int i=0;
    while(i<size)
    {
        if(arr[i]==data)
        {
            return i;
        }
        else if (arr[i]<data)
        {
            i+=jump;
        }
        else
        {
            break;
        }
    }

    if(i>=size)
    {
        return -1;
    }
    else
    {
        while(jump--)
        {
            i=i-1;
            if(arr[i]==data)
                return i;
        }
    }
    
    return -1;
}


int main()
{
    int arr[]={2,6,34,45,67,68,75,98,236,321,433};
    int size=sizeof(arr)/sizeof(int);
   

    //searching operations
    jumpSearch(arr,size,34)?cout<<"not found\n":cout<<"found\n";
    jumpSearch(arr,size,67)?cout<<"not found\n":cout<<"found\n";
    jumpSearch(arr,size,98)?cout<<"not found\n":cout<<"found\n";
    jumpSearch(arr,size,231)?cout<<"not found\n":cout<<"found\n";
    return 0;
}