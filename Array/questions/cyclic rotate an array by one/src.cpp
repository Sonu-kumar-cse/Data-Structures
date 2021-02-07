#include<iostream>
using namespace std;

void rotateByOne(int arr[],int n)
{
    int x=arr[n-1];
    for(int i=n-1;i>0;i--)
    {
        arr[i]=arr[i-1];
    }
    arr[0]=x;
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
    rotateByOne(arr,n);
    cout<<"array after one rotation "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}