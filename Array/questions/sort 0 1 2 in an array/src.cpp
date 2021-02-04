#include<iostream>
using namespace std;

void swap(int arr[],int a,int b)
{
    int temp=arr[a];
    arr[a]= arr[b];
    arr[b]=temp;
}

void sort_0_1_2(int arr[],int n)
{
    int low,mid,high;
    low=mid=0;
    high=n-1;
    
    while(mid<=high)
    {
        if(arr[mid]==0)
        {
            swap(arr,mid,low);
            low++;
            mid++;
        }
        else if(arr[mid]==1)
        {
            mid++;
        }
        else
        {
            swap(arr,mid,high);
            high--;
        }
    }
}

int main()
{
    int n;
    cout<<"enter size of array ";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array (only 0,1,2) "<<endl;

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    sort_0_1_2(arr,n);

    cout<<"after sorting "<<endl;

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}