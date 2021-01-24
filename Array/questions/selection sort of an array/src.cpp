#include<iostream>
using namespace std;
//selection sort
/*
    selection sort is a simple sorting algorithm. This sorting 
    algorithm is an in-place comparision-based algorithm in which 
    the list is divided into two parts, the sorted part at the left
    end and the unsorted part at the right end. Initially, the sorted
    part is the empty list.
    The smallest element is selected from the unsorted array and swapped with 
    the leftmost element, and that becomes a part of the sorted array.
    This process continues moving unsorted array boundary by one 
    element right.

    This algorithm is not suitable for large data sets as its average and 
    worst case complexities are of O(n2), where n is the number of items.

*/

int main()
{
    int n;
    cout<<"enter size of array"<<endl;
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
    cout<<endl;
    //sorting algorithm
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[min]>arr[j])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }

    cout<<"array after sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }    
    cout<<endl;
    return 0;
}