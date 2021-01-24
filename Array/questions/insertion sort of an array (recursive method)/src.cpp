#include<iostream>
using namespace std;

void insertionSort(int arr[],int n, int i)
{
    if(i==n)
    {
        return;
    }

    int j=i;
    while(j!=0)
    {
        if(arr[j]<arr[j-1])
        {
            int temp=arr[j];
            arr[j]=arr[j-1];
            arr[j-1]=temp;
        }
        else
        {
            break;
        }
        j--;
        
    }
    insertionSort(arr,n,i+1);


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
    cout<<"array before sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    insertionSort(arr,n,1);
    cout<<endl<<"array after sorting"<<endl;
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;

}