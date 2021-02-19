#include<iostream>
#include<vector>
using namespace std;

vector<int> getFixedPoints(int arr[],int n)
{
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==i+1)
        {
            vec.push_back(arr[i]);
        }
    }
    return vec;

}


int main()
{
    int n;
    cout<<"enter size of array ";
    cin>>n;
    int arr[n];
    cout<<"enter elemnets of array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    vector<int> v=getFixedPoints(arr,n);

    if(v.size()==0)
    {
        cout<<"no fixed values found";
        return 0;
    }

    cout<<"fixed values are"<<endl;

    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }


    return 0;

}