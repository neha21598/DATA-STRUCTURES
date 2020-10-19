#include<iostream>
#include<string.h>
using namespace std;
class stacks
{
public:
	int *arr,top1,top2,maxSize;

	stacks(int size)
	{
		maxSize=size;
		arr=new int[size];
		top1=size/2+1;
		top2=size/2;
	}

	void push1(int data)
	{
		if(top1>0)
		{
			top1--;
			arr[top1]=data;
			cout<<"Element pushed:\t"<<data<<"\n";
		}
		else
		{
			cout<<"Stack Overflow!!\n";
		}
	}

	void push2(int data)
	{
		if(top2<(maxSize-1))
		{
			top2++;
			arr[top2]=data;
			cout<<"Element Pushed is:\t"<<data<<"\n";
		}
		else
		{
			cout<<"Stack Overflow!!\n";
		}
	}

	void pop1()
	{
		if(top1<=maxSize/2)
		{
			int temp=arr[top1];
			top1++;
			cout<<"Element Poped is:\t"<<temp<<"\n";
		}
		else
		{
			cout<<"Stack Underflow!!\n";
		}
	}

	void pop2()
	{
		if(top2>(maxSize/2+1))
		{
			int temp=arr[top2];
			top2--;
			cout<<"Element Poped is:\t"<<temp<<"\n";
		}
		else
		{
			cout<<"Stack Underflow!!\n";
		}
	}

	void printStack()
	{
		for(int i=top1;i<=top2;i++)
		{
			cout<<arr[i]<<"\n";
		}
	}
};

int main()
{
	stacks s1(5);
	int ch,e;
	  do
    {
        cout<<"\n1.push In stack1 \n2.push In stack2 \n 3.pop from stack1 \n 4.pop from stack2 \n0.Exit";
        cout<<"\nEnter Your choice";
        cin>>ch;
    
    
    switch(ch)
    {
        
        case 1:
        cout<<"Enter element";
        cin>>e;
        s1.push1(e);
        break;
        
        case 2:
        cout<<"Enter element";
        cin>>e;
        s1.push2(e);
        break;
        
        case 3:
        s1.pop1();
        break;
        
        case 4:
        s1.pop2();
        break;
        
        case 0:
        cout<<"Exit";
        break;
    }
    }while(ch!=0);
	getchar();
}
