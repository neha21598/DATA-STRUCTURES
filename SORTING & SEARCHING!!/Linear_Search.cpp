#include<iostream>
using namespace std;
int n,arr[10],i,key;

int linearSearch(int arr[],int n,int key)
{
    for(int i=0;i<n;i++)
    {
        if(key==arr[i])
        {
        return 1; 
        }
    }
}

int main()
{
    int result;
    
    cout<<"Enter size\n";
    cin>>n;
    
    
    cout<<"Enter array elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    
    cout<<"\nEnter the  key element:\n";
    cin>>key;
 
    result=linearSearch(arr,n,key);   
     
    if(result==1)
    {
        cout<<"Number  found!!!\n";
    }
    else
    {
           cout<<"Number not  found\n";
    }
	getchar();
}
