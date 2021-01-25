#include<iostream>
using namespace std;

int partiotion(int arr[],int lb,int ub)
{
    int pivot=lb;

    int i=lb;
    int j=ub;

    while(i<j)
    {
        while(arr[i]<=arr[lb] && i<=ub)
        {
            i++;
        }
        while(arr[j]>arr[lb] && j>=lb) 
        {
            j--;
        }
        if(i<j)
        {
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[j];
    arr[j]=arr[pivot];
    arr[pivot]=temp;

    return j;
}

void quickSort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=partiotion(arr,lb,ub);
        quickSort(arr,lb,mid);
        quickSort(arr,mid+1,ub);
    }
}

int main()
{
    int n;
    cout<<"enter size of array ";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    cout<<"array before sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    quickSort(arr,0,n-1);
    cout<<endl<<"array after sorting"<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

}