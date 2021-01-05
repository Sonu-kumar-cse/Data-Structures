#include<iostream>
using namespace std;

int main()
{

    int n;
    cout<<"enter size of array ";
    cin>>n;
    int arr[n];

    cout<<"enter "<<n<<" elements"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"array is\n";
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";

    }

    return 0;

}