#include<iostream>
using namespace std;


void bubbleSort(int arr[],int n)
{
    if(n==1)
        return;
    
    bool isSorted=true;
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        {
            int temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            isSorted=false;
        }
    }
    if(isSorted)
        return;

    bubbleSort(arr,n-1);
}

int main()
{
    int n;
    cout<<"enter size of array ";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"array before sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    bubbleSort(arr,n);

    cout<<"array after sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}