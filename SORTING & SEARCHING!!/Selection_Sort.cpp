#include<iostream>
using namespace std;

void SelectionSort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    
}

int main()
{
	int size,arr[100],n;
	cout<<"Enter the size of Array:\n";
	cin>>n;
	cout<<"Enter the array Elements:\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"The Elements Before Sorting are:\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
    
    SelectionSort(arr,n);
    	cout<<"\nThe Elements After Sorting are:\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	getchar();
}