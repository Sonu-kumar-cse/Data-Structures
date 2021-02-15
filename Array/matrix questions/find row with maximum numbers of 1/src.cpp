#include<iostream>
using namespace std;

int main()
{

    int r,c;
    cout<<"enter number of row ";
    cin>>r;
    cout<<"enter number of column ";
    cin>>c;

    int matrix[r][c];

    cout<<"enter elements of the matrix "<<endl;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>matrix[i][j];
        }
    }

    int row=-1;
    int count=0;

    for(int i=0;i<r;i++)
    {
        int currentCount=0;
        for(int j=0;j<c;j++)
        {
            if(matrix[i][j]==1)
            {
                currentCount++;
            }
        }
        if(currentCount>count)
        {
            count=currentCount;
            row=i;
        }
    }

    cout<<"row with maximum number of 1 is "<<row<<" it has total "<<count<<" number of 1";
    return 0;
}