#include<iostream>
using namespace std;

int getMax(int arr[],int size)
{
    int max=arr[0];
    for(int i=0;i<size;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    return max;
}

int getMin(int arr[],int size)
{
    int min=arr[0];
    for(int i=0;i<size;i++)
    {
        if(min>arr[i])
        {
            min=arr[i];
        }
    }
    return min;
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

    cout<<"maximum element = "<<getMax(arr,n)<<endl;
    cout<<"minimm element = "<<getMin(arr,n)<<endl;

}