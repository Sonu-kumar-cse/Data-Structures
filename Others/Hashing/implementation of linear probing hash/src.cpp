#include<iostream>
using namespace std;

//fuction for getting index for a data 
int getIndex(int data,int hashSize)
{
    return data%hashSize;
}

// fuction for creationg a hash
void createHash(int hash[],int arr[],int n,int hashSize)
{
    
    for(int i=0;i<n;i++)
    {
        int index=getIndex(arr[i],hashSize);
        if(hash[index]==INT32_MAX)
        {
            hash[index]=arr[i];
        }
        else
        {
            int prev=index-1;
            if(index==0)
            {
                prev=hashSize-1;
            }
            while(hash[index]!=INT32_MAX && index!=prev)
            {
                index=(index+1)%hashSize;

            }
            if(hash[index]==INT32_MAX)
            {
                hash[index]=arr[i];
            }
            else
            {
                cout<<"hash is full"<<endl;
            }   
        }
    }

}

// function for searching data 
void searchData(int data,int hash[],int hashSize)
{
    int index=getIndex(data,hashSize);

    if(hash[index]==data)
    {
        cout<<"data found"<<endl;
        return;
    }
    else
    {
        int prev=index-1;
        if(index==0)
        {
            prev=hashSize-1;
        }
        while(hash[index]!=INT32_MAX  && index!=prev)
        {
            index=(index+1)%hashSize;
            if(hash[index]==data)
            {
                cout<<"data found"<<endl;
                return;
            }
        }
    }
    cout<<"not found"<<endl;
    return;
    
}


int main()
{
    //simple array
    int arr[]={2,3,22,34,5,3,4,45,6,12};
    int n=sizeof(arr)/sizeof(int);
    
    //hash array
    const int HASH_SIZE=10;
    int hash[HASH_SIZE];

    //filling same garbage value to whole hash
    for(int i=0;i<HASH_SIZE;i++)
    {
        hash[i]=INT32_MAX;
    }


    //creating hash
    createHash(hash,arr,n,HASH_SIZE);

    //searching some data
    searchData(23,hash,HASH_SIZE);
    searchData(22,hash,HASH_SIZE);
    searchData(4,hash,HASH_SIZE);
    searchData(3,hash,HASH_SIZE);
    searchData(12,hash,HASH_SIZE);
    searchData(122,hash,HASH_SIZE);
    
    return 0;

}