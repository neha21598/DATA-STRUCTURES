#include<iostream>
using namespace std;
int arr[50];
int mid;
int Binarysearch(int start,int end,int key)
	{
		if(start==end)
		{
			if(key==arr[start])
			return(start);
			else
			return(-1);
		}
		else
		{
			mid=(start+end)/2;
			if(key==arr[mid])
			{
				return (mid);
			}
			else
			{
				if(key<arr[mid])
				return (Binarysearch(start,mid-1,key));
				else
				return(Binarysearch(mid+1,end,key));
			}
		}
	}
	
int main()
{
	int start,end,key,mid,pos,size,i;
	cout<<"enter size\n";
	cin>>size;
	cout<<"enter data\n";
	for(i=0;i<size;i++)
	{
		cin>>arr[i];
	}
	cout<<"enter no to be search\n";
	cin>>key;
	pos=Binarysearch(0,size-1,key);
	if(pos==-1)
	cout<<"Element not found\n";
	else
	cout<<"found at "<<pos+1;
	
}
