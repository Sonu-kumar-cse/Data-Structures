#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"enter size of array ";
    cin>>n;
    int arr[n];
    cout<<"enter element of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int x;
    cout<<"enter element you want to find ";
    cin>>x;
    
    int first,last;
    first=last=-1;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            first=last=i;
            break;
        }
    }
    if(first==-1)
    {
        cout<<"element not found";
    }
    else
    {
        for(int i=first;i<n;i++)
        {
            if(arr[i]==x) last=i;
            else break;
        }
        cout<<"element is from index "<<first<<" to "<<last;
    }



    return 0;
}