#include<iostream>
using namespace std;

void build(int tree[],int a[],int i,int start, int end,int s,int e)
{
    //
    if(start>e || end<s)
    {
        return;
    }
    if(start==end)
    {
        tree[i]=a[start];
        return;
    }

    int mid=(start+end)/2;

    build(tree,a,2*i,start,mid,s,e);
    build(tree,a,2*i+1,mid+1,end,s,e);

    int left=tree[2*i];
    int right=tree[2*i+1];

    tree[i]=min(left,right);
    
    
   
}


int query(int tree[],int i,int start, int end,int s,int e)
{
    //if out of range
    if(e<start || end<s)
    {
        return INT32_MAX;
    }

    if(start>=s && end<=e)
    {
        return tree[i];
    }

    int mid= (start+end)/2;
    int left=query(tree,2*i,start,mid,s,e);
    int right=query(tree,2*i+1,mid+1,end,s,e);

    return min(left,right);
}


void update(int tree[], int i,int s,int e,int index,int value)
{

    if(s>index || e<index)
    {
        return;
    }

    if(s==e && s==index)
    {
        tree[i]=value;
        return;
    }

    int mid=(s+e)/2;

    update(tree,i*2,s,mid,index,value);
    update(tree,i*2+1,mid+1,e,index,value);

    int left=tree[i*2];
    int right=tree[2*i+1];

    tree[i]=min(left,right);

}

int main()
{
    int a[]={2,4,1,-2,0,3};
    int n=sizeof(a)/sizeof(int);
    int tree[n*4+1];
    int i=1;
    int s=0;
    int e=n-1;

    build(tree,a,1,s,e,s,e);

    int k=sizeof(tree)/sizeof(int);


    update(tree,1,0,5,3,5);
    
    
    for(int j=0;j<k;j++)
    {
        cout<<tree[j]<<" ";
    }
    cout<<endl;
    
    cout<<query(tree,1,0,5,3,5);


    return 0;
}