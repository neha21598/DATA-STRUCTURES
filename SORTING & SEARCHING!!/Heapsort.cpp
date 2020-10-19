#include<iostream>
using namespace std;
void display(int *array, int size) 
{
   for(int i = 0; i<size; i++)
   {
      cout << array[i] << " ";
   }
   cout << endl;
}
void HeapSort(int *arr, int size)
{
  int i,j,key,flag,t;
   for(i=size-1;i>0;i--)
     {
       for(j=1;j<i;j++) 
         {
           key=j;
           flag=0;
           while(key>0 && key/2 >=0 && flag!=1 )
            {
               if(arr[key/2]<arr[key])
                {
                  t=arr[key/2];
                  arr[key/2]=arr[key];
                  arr[key]=t;
                }
               else
                flag=1;
            }

         } 
	   t=arr[i];
	   arr[i]=arr[0];
	   arr[0]=t;
     }
}
int main()
{
   int n;
   cout << "Enter the number of elements: ";
   cin >> n;
   int *arr=new int[n];   
   cout <<"Enter elements:" << endl;
   for(int i = 0; i<n; i++)
   {
      cin >> arr[i];
   }
   
   HeapSort(arr, n);
   cout << "Array after Sorting: ";
   display(arr, n);
}
