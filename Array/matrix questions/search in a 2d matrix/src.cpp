#include<iostream>
#include<vector>
using namespace std;


//this function will work omly if matrix is sorted 
bool findValueInSortedMatrix(vector<vector<int>> matrix,int r,int c,int target)
{
    int row=-1;
    for(int i=0;i<r;i++)
    {
        if(target>=matrix[i][0] && target<=matrix[i][c-1])
        {
            row=i;
            break;
        }
    }
    if(row!=-1)
    {
        for(int i=0;i<c;i++)
        {
            if(matrix[row][i]==target)
            {
                return true;
            }
        }
    } 

    return false;
}

int main()
{
    int r;
    cout<<"enter number of rows ";
    cin>>r;
    int c;
    cout<<"enter number of columns ";
    cin>>c;

    vector<vector<int>> matrix(r);

    cout<<"enter "<<r*c<<" elements of matrix"<<endl;

    for(int i=0;i<r;i++)
    {
        matrix[i].assign(c,0);
        for(int j=0;j<c;j++)
        {
            cin>>matrix[i][j];
        }
    } 
    
    int target;
    cout<<"enter value you want to check wether it is present in the matrix or not ";
    cin>>target;
    if(findValueInSortedMatrix(matrix,r,c,target))
    {
        cout<<"value is present ";
    }
    else
    {
        cout<<"value is not present";
    }

    return 0;
}
