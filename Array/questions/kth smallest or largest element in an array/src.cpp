#include<iostream>
using namespace std;

int partition(int arr[],int l,int r)
{
    int i=l;
    for(int j=l;j<r;j++)
    {
        if(arr[j]<arr[r])
        {
            int temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
            i++;
        }
    }
    int temp=arr[i];
    arr[i]=arr[r];
    arr[r]=temp;
    return i;
}

void partialQuickSort(int arr[],int l,int r,int k)
{
    if(l<r)
    {
        int pivot=partition(arr,l,r);
        if(pivot==k)
        {
            return;
        }
        
        if(pivot<k)
        {
            partialQuickSort(arr,pivot+1,r,k);
        }
        else
        {
            partialQuickSort(arr,l,pivot-1,k);
        }
    }
}

int getKthSmallest(int arr[],int l,int r,int k)
{
    partialQuickSort(arr,l,r,k);
    return arr[k];
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

    int k;
    cout<<"enter k for finding kth smallest element ";
    cin>>k;

    int result=getKthSmallest(arr,0,n-1,k-1);

    cout<<k<<"th smallest element="<<result;



    return 0;
}