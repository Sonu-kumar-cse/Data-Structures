#include<bits/stdc++.h>
using namespace std;

//fundtion for swapping in an array
void swapArr(int *arr,int i,int j)
{
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
}
//bubbleSort implementaion
void bubbleSort(int *arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(arr[j]>arr[j+1])
			{
				swapArr(arr,j,j+1);
			}
		}
	}
}
//insetionSort implementation
void insertionSort(int *arr,int n)
{
	for(int i=1;i<n;i++)
	{
		int j=i;
		while(j>0)
		{
			if(arr[j]<arr[j-1])
			{
				swapArr(arr,j,j-1);
			}
			else break;
			j--;
		}
	}
}
//selectionSort implementation
void selectionSort(int *arr,int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min=i;
		for(int j=i;j<n;j++)
		{
			if(arr[min]>arr[j])
				min=j;
		}
		swapArr(arr,i,min);
	}
}
//quickSort helping function
int partition(int *arr,int low,int high)
{
	int pivot=low;
	int i=low;
	int j=high;

	while(i<j)
	{
		while(arr[i]<=arr[pivot] && i<high) i++;
		while(arr[j]>arr[pivot] && j>low) j--;
		if(i<j)
		{
			swapArr(arr,i,j);
		}
	}
	swapArr(arr,j,pivot);
	return j;
}

//quickSort implementaion
void quickSort(int *arr,int low,int high)
{
	if(low<high)
	{
		int pivot=partition(arr,low,high);
		quickSort(arr,low,pivot-1);
		quickSort(arr,pivot+1,high);
	}
}

//helping function for mergeSort
void merge(int *arr,int low,int mid,int high)
{
	int brr[high-low+1];
	int i=low;
	int j=mid+1;
	int cursor=0;
	while(i<=mid && j<=high)
	{
		if(arr[i]<arr[j])
		{
			brr[cursor]=arr[i];
			i++;
		}
		else
		{
			brr[cursor]=arr[j];
			j++;
		}
		cursor++;
	}
	while(i<=mid)
	{
		brr[cursor]=arr[i];
		i++;cursor++;
	}
	while(j<=high)
	{
		brr[cursor]=arr[j];
		j++;cursor++;
	}

	int index=low;
	for(int i=0;i<cursor;i++)
	{
		arr[index]=brr[i];
		index++;

	}
}
//mergeSort implementaion
void mergeSort(int *arr,int low,int high)
{
	if(low<high)
	{
		int mid=(low+high)/2;
		mergeSort(arr,low,mid);
		mergeSort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

//fuction to print array
void printArray(int *arr,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}


int main()
{
	cout<<"enter size of array :";
	int n;
	cin>>n;
	int arr[n];
	cout<<"enter element of array"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"array before sorting"<<endl;
	printArray(arr,n);
	
	// cout<<"array after using bubbleSort"<<endl;
	// bubbleSort(arr,n);
	// printArray(arr,n);

	// cout<<"array after using selectionSort"<<endl;
	// selectionSort(arr,n);
	// printArray(arr,n);
	
	// cout<<"array after using insetionSort"<<endl;
	// insertionSort(arr,n);
	// printArray(arr,n);

	// cout<<"array after using quickSort"<<endl;
	// quickSort(arr,0,n-1);
	// printArray(arr,n);

	cout<<"array after using quickSort"<<endl;
	mergeSort(arr,0,n-1);
	printArray(arr,n);

	return 0;
}