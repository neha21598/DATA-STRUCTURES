#include<iostream>
using namespace std;

void Merger(int arr[],int start,int mid,int end)
{
	int i=start,j=mid+1,temp[100],ti=start;
	if(arr[i]<arr[j])
	{
		temp[ti++]=arr[i++];
	}
	else
	{
		temp[ti++]=arr[j++];
	}

	while(i<=mid)
	{
		temp[ti++]=arr[i++];
	}

	while(j<=end)
	{
		temp[ti++]=arr[j++];
	}

	for(i=start;i<=end;i++)
	{
		arr[i]=temp[i];
	}
}

void MergeSort(int arr[],int start,int end)
{
	if(start<end)
	{
		int mid=(start+end)/2;
		MergeSort(arr,start,mid);
		MergeSort(arr,mid+1,end);
		Merger(arr,start,mid,end);
	}
}

int main()
{
	int size,arr[100],n,start,end;
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
	start=arr[0];
	end=n-1;

	MergeSort(arr,start,end);

    cout<<"\nThe Elements After Sorting are:\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}

	getchar();
}