#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<int> intersection(int arr[],int brr[],int m,int n)
{
    vector<int> v;

    int i=0;
    int j=0;

    while(i<m && j<n)
    {
        if(arr[i]==brr[j])
        {
            v.push_back(arr[i]);
            i++;j++;
        }
        else if(arr[i]<brr[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return v;

}

vector<int> getUnion(int arr[],int brr[],int m,int n)
{
    vector<int> v;
    int i=0;
    int j=0;

    while(i<m && j<n)
    {
        if(arr[i]==brr[j])
        {
            v.push_back(arr[i]);
            i++;j++;
        }
        else if(arr[i]<brr[j])
        {
            v.push_back(arr[i]);
            i++;
        }
        else
        {
            v.push_back(brr[j]);
            j++;
        }
    }
    while(i<m)
    {
        v.push_back(arr[i]);
        i++;
    }
    while(j<n)
    {
        v.push_back(brr[j]);
        j++;
    }

    return v;

}

int main()
{

    int m;
    cout<<"enter size of first array ";
    cin>>m;
    int arr[m];
    cout<<"enter elements for first array"<<endl;
    for(int i=0;i<m;i++)
    {
        cin>>arr[i];
    }

    int n;
    cout<<"enter size of second array "<<endl;
    cin>>n;
    int brr[n];
    cout<<"enter elements of array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>brr[i];
    }

    sort(arr,arr+m);
    sort(brr,brr+n);

    vector<int> v1= intersection(arr,brr,m,n);

    cout<<"intersection of both arrays"<<endl;
    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<" ";
    }

    vector<int> v2= getUnion(arr,brr,m,n);

    cout<<endl<<"union of both array "<<endl;
    for(int i=0;i<v2.size();i++)
    {
        cout<<v2[i]<<" ";
    }

   return 0;
}