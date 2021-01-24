#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter size of an array ";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array"<<endl;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    
    cout<<"array before sorting"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    //insertion sort algorithm

    for(int i=1;i<n;i++)
    {
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
        
    }

    cout<<endl<<"after sorting array is"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }


    return 0;

}