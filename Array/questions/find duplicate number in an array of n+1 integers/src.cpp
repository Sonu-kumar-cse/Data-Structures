#include<iostream>
using namespace std;

int findDuplicate(int arr[],int n)
{
    int crr[n+1];
    for(int i=1;i<n+1;i++)
    {
        crr[i]=0;
    }

    for(int i=0;i<n+1;i++)
    {
        crr[arr[i]]++;
    }
    int max=1;
    for(int i=1;i<n+1;i++)
    {
        if(crr[max]<crr[i])
        {
            max=i;
        }
    }
    return max;
}

int findDuplicate1(int arr[],int n)
{
    int slow=arr[0];
    int fast=arr[0];
    do
    {
        slow=arr[slow];
        fast=arr[arr[fast]];
    } while (slow!=fast);

    fast=arr[0];
    while(fast!=slow)
    {
        fast=arr[fast];
        slow=arr[slow];
    }
    return slow;
    
}


int main()
{
    int arr[]={1,2,1,3,4,5};
    int n=5;
    cout<<findDuplicate1(arr,n);
    
}