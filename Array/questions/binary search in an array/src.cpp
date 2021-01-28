#include<iostream>
using namespace std;

//binary search algo only works on sorted array
int binarySearch(int arr[],int size,int data)
{
    int left=0;
    int right=size-1;
    int mid=(left+right)/2;

    while(left<=right)
    {
        if(arr[mid]==data)
        {
            return mid;
        }
        else if(arr[mid]<data)
        {
            left=mid+1;
            mid=(left+right)/2;
        }
        else
        {
            right=mid-1;
            mid=(left+right)/2;
        }
    }
    return -1;

}
int main()
{
    int arr[]={4,7,35,56,75,86,156,174,256};
    int size=sizeof(arr)/sizeof(int);

    //searching operations
    binarySearch(arr,size,45)==-1? cout<<"not found\n" :  cout<<"found\n";
    binarySearch(arr,size,86)==-1? cout<<"not found\n" :  cout<<"found\n";
    binarySearch(arr,size,256)==-1? cout<<"not found\n" :  cout<<"found\n";
    return 0;
}