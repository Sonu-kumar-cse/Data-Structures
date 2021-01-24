#include<iostream>
using namespace std;
/*
    Bubble sort is a simple sorting algorithm. This sorting algorithm is comparision-based algorithm
    in which each pair of adjacent elements is compared and the elements are swapped if they are 
    not in order. This algorithm is not suitable for large data sets as its average and worst case
    complexity are of O(n2) where n is the number of items.

*/
int main()
{

    int n;
    cout<<"enter size of the array ";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"before sorting array is ";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<n-1;i++)
    {
        bool isSorted=true;    
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                isSorted=false;
            }
        }
        if(isSorted)
            break;
    }
    cout<<"array after sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }
    cout<<endl;
    return 0;



}