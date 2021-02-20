#include<iostream>
using namespace std;

int searchInRotatedSortedArray(int arr[],int n,int target)
{
    int left=0;
    int right=n-1;

    while(left<=right)
    {
        int mid=(left+right)/2;
        if(arr[mid]==target)
        {
            return mid;
        }
        else if(arr[left]<=arr[mid])
        {
            if(arr[mid]>target && arr[left]<=target)
            {
                right=mid-1;
            }
            else 
            {
                left=mid+1;
            }
        }
        else
        {
            if(arr[mid]<target && arr[right]>=target)
            {
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }
    }
    return -1;
}

int main()
{
    return 0;
}