#include<iostream>
using namespace std;
int arr[100],i,j;

void BubbleSort(int arr[],int size)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<size-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{ 
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

int main()
{
	int size,e;
	cout<<"Enter the size of array:\n";
	cin>>size;

	cout<<"Enter the array Elements:\n";
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	BubbleSort(arr,size);
	cout<<"After Sortingg!!:\n";
	for(int i=0;i<size;i++)
	{
	    cout<<arr[i]<<"\t";
	}
	getchar();
}