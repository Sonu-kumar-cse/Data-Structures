#include<iostream>
using namespace std;

void swap(int arr[],int i,int j)
{
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

void rearrange(int arr[],int n)
{
    int i=0;
    int j=n-1;

    while(i<j)
    {
        if(arr[i]>arr[j] && arr[i]>0)
        {
            swap(arr,i,j);
            i++;
            j--;
        }
        else{
            if(arr[i]<0)
            {
                i++;
            }
            if(arr[j]>0)
            {
                j--;
            }
        }
    }

}

void rearrange2(int arr[],int n)
{
    int j=0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]<0)
        {
            if(i!=j)
            {
                swap(arr,i,j);
                j++;
            }
        }
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
    
    rearrange2(arr,n);
 
    cout<<"array after rearranging"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}