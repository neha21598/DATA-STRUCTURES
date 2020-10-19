#include<iostream>
using namespace std;
int key;
void InsertionSort(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            key=arr[j];
            while(j>0 && key<arr[j-1])
            {
                arr[j]=arr[j-1];
                j--;
            }
             arr[j]=key;
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
    
    InsertionSort(arr,n);
    	cout<<"\nThe Elements After Sorting are:\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
}