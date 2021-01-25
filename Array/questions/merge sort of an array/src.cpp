#include<iostream>
using namespace std;

void merge(int arr[],int lb,int mid, int ub)
{
    int n1= mid-lb+1;
    int n2= ub-mid;

    int a1[n1],a2[n2];

    for(int i=0;i<n1;i++)
    {
        a1[i]=arr[lb+i];
    }
    for(int i=0;i<n2;i++)
    {
        a2[i]=arr[mid+i+1];
    }

    int i=0;
    int j=0;
    int k=lb;

    while(i<n1 && j<n2)
    {
        if(a1[i]<a2[j])
        {
            arr[k]=a1[i];
            i++; k++;
        }
        else
        {
            arr[k]=a2[j];
            j++; k++;
        }
        
    }

    while(i<n1)
    {
        arr[k]=a1[i];
        i++; k++;
    }
    while(j<n2)
    {
        arr[k]=a2[j];
        j++; k++;
    }


}


void mergeSort(int arr[],int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergeSort(arr,lb,mid);
        mergeSort(arr,mid+1,ub);

        merge(arr,lb,mid,ub);
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

    mergeSort(arr,0,n-1);

    cout<<endl<<"array after sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
    return 0;
}