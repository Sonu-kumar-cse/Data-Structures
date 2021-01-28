#include<iostream>
using namespace std;

void reverseArray(int arr[],int size)
{
    for(int i=0;i<size/2;i++)
    {
        int temp=arr[i];
        arr[i]=arr[size-1-i];
        arr[size-1-i]=temp;
    }
}

int main()
{
    int n;
    cout<<"enter size of array ";
    cin>>n;
    
    int arr[n];
    cout<<"enter elements of array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    reverseArray(arr,n);
    cout<<"after reversing the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
 
    return 0;
}