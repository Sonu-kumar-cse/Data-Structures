#include<bits/stdc++.h>
using namespace std;

void heapify(int *arr,int i, int n)
{
    int left=i*2<=n?i*2:-1;
    int right=i*2+1<=n?i*2+1:-1;
    if(left!=-1 && right!=-1)
    {
        int larger=arr[left]>arr[right]?left:right;
        if(arr[larger]>arr[i])
        {
            int temp=arr[larger];
            arr[larger]=arr[i];
            arr[i]=temp;
            heapify(arr,larger,n);
        }
    }
    else if(left!=-1)
    {
        if(arr[left]>arr[i])
        {
            int temp=arr[i];
            arr[i]=arr[left];
            arr[left]=temp;
        }
    }
    else
    {
        return;
    }
}

void buildHeap(int *arr,int n)
{
    for(int i=n/2;i>=1;i--)
    {heapify(arr,i,n);}
}

void heapSort(int *arr,int n)
{
    buildHeap(arr,n);
    int size=n;
    for(int i=1;i<=n;i++)
    {
        int temp=arr[size];
        arr[size]=arr[1];
        arr[1]=temp;
        size--;
        heapify(arr,1,size);
    }
}

int main()
{

    int n;
    cout<<"enter size of array ";
    cin>>n;
    int arr[n+1];
    cout<<"enter elements of array";
    for(int i=1;i<=n;i++)
    {
        cin>>arr[i];
    }
    heapSort(arr,n);
    cout<<"array after sorting"<<endl;

    for(int i=1;i<=n;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;
}