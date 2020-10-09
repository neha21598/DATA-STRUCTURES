#include<iostream>
using namespace std;
int Q[100],rear,front,count,maxSize,z;

void initQueue(int size)
{
	maxSize=size-1;
	rear,front=-1;
}
int isFull()
{
	if(rear==maxSize-1)
	{
		return 1;
	}
	else
		return 0;
}
void Enqueue(int a)
{
	if(isFull())
	{
		cout<<"Queue is FULL";
	}
	else
	{
	rear++;
	Q[rear]=a;
	}
}

int isEmpty()
{
	if(front==maxSize)
	{
		return 1;
	}
	else
		return 0;
}

int Dequeue()
{
	if(isEmpty())
	{
		cout<<"Queue is Already EMPTY!";
	}
	else
	{
		int temp;
		temp=Q[front];
		front++;
		return temp;
	}
}

void Printqueue()
{
	for(int i=front;i<=rear;i++)
	{
	    cout<<Q[i]<<"  \n";
	}
}

int main()
{
	int size,option;
	cout<<"Enter the size of Queue:\n";
	cin>>size;
	initQueue(size);
	do
	{
	cout<<"Select one option:\n 1.Enqueue\n2.Dequeue\n3.PrintQueue\n0.Quit\n";
	cin>>option;
	switch(option)
	{
	case 1:
		cout<<"Enter to Enqueue:\n";
		cin>>z;
		Enqueue(z);
		break;

	case 2:
		int temp;
		temp=Dequeue();
		cout<<"Dequeued the element!\n"<<temp;
		break;

	case 3:
		Printqueue();
		break;

	case 0:
		cout<<"Exiting";

	default:
		cout<<"Invalid Choice!";

	}
	}while(option!=0);
	getchar();
	return 0;
}