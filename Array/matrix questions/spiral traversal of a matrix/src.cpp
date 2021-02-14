#include<iostream>
using namespace std;

int main()
{
    int m,n;
    cout<<"enter number of rows ";
    cin>>m;
    cout<<"enter number of columns ";
    cin>>n;

    int matrix[m][n];
    cout<<"enter "<<m*n<<" elements of matrix "<<endl;
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>matrix[i][j];
        }
    }

    cout<<"spiral traversl of matrix"<<endl;

    //code for spiral traversal
    int top=0;
    int down=m-1;
    int left=0;
    int right=n-1;
    int direction=0;

    while(top<=down && left<=right)
    {
        if(direction==0)
        {
            for(int i=left;i<=right;i++)
            {
                cout<<matrix[top][i]<<" ";
            }
            top++;
        }
        else if(direction==1)
        {
            for(int i=top;i<=down;i++)
            {
                cout<<matrix[i][right]<<" ";
            }
            right--;
        }
        else if(direction==2)
        {
            for(int i=right;i>=left;i--)
            {
                cout<<matrix[down][i]<<" ";
            }
            down--;
        }
        else
        {
            for(int i=down;i>=top;i--)
            {
                cout<<matrix[i][left]<<" ";
            }
            left++;
        }
        direction=(direction+1)%4;
    }


    return 0;
}