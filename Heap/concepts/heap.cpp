#include<bits/stdc++.h>
using namespace std;

class Heap
{
    private:
        int n;
        vector<int> heap;
    public:
        Heap()
        {
            n=0;
            heap.push_back(-1);
        }
        void insertData(int data);
        void deleteData();
        void printData();

        
};

void Heap::printData()
{
    for(int i=1;i<=n;i++)
    {
        cout<<heap[i]<<" ";
    }
}
void Heap::insertData(int data)
{
    n++;
    heap.push_back(data);
    int i=n;
    while(i>1)
    {
        int parent=i/2;
        if(heap[parent]<heap[i])
        {
            int temp=heap[i];
            heap[i]=heap[parent];
            heap[parent]=temp;
            i=parent;
        }
        else
        {
            return;
        }
    }
}
void Heap::deleteData()
{
    heap[1]=heap[n];
    heap.pop_back();
    n--;
    int i=1;
    while(i<n)
    {
        int left=i*2<=n?i*2:-1;
        int right=i*2+1<=n?i*2+1:-1;
        if(left!=-1 && right!=-1)
        {
            int larger=heap[left]>heap[right]?left:right;
            if(heap[larger]>heap[i])
            {
                int temp=heap[larger];
                heap[larger]=heap[i];
                heap[i]=temp;
                i=larger;
            }
            else {
                return;
            }
        }
        else if(left!=-1)
        {
            if(heap[left]>heap[i])
            {
                int temp=heap[left];
                heap[left]=heap[i];
                heap[i]=temp;
                i=left;
            }
            else 
                return;
        }
        else if(right!=-1)
        {
            if(heap[right]>heap[i])
            {
                int temp=heap[right];
                heap[right]=heap[i];
                heap[i]=temp;
                i=right;
            }
            else 
                return;
        }
        else 
            return;
    }
}


int main()
{

    Heap h;
    h.insertData(50);
    h.insertData(60);
    h.insertData(10);
    h.insertData(20);
    h.insertData(40);
    h.insertData(70);
    h.insertData(30);
    h.insertData(80);
    h.printData();
    h.deleteData();
    cout<<endl;
    h.printData();
    return 0;
}