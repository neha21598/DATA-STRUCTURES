#include<iostream>
using namespace std;
int rear,front,Q[100],z,countt,maxSize;

void initQueue(int size)
{
	front=0;
	rear=-1;
	maxSize=size;
	countt=0;
}

int isFull()
{
	if(countt==maxSize)
		return 1;
	else
	return 0;
}

void Enqueue(int a)
{
	if(isFull())
		cout<<"Queue is FULL\n";
	else
	{
		rear=(rear+1)%maxSize;
		countt++;
	    Q[rear]=a;
	}
}

int isEmpty()
{
	if(countt==0)
		return 1;
	else 
		return 0;
}

int Dequeue()
{
	if(isEmpty())
		cout<<"Queue is already EMPTY!!\n";
	else
	{
		countt--;
		z=Q[front];
		front=(front+1)%maxSize;
		return z;
	}
}

void PrintQueue()
{
	int c,i;
	i=front,c=0;
	while(c<countt)
	{
		cout<<Q[i];
		i=(i+1)%maxSize;
		c=c+1;
	}
}

int atTop()
{
	return Q[front];
}

int main()
{
	int option;
	cout<<"Enter the size for the Queue:\n";
	cin>>z;
	initQueue(z);
	do
	{
		cout<<"Select an Option:\n1.Enqueue\n2.Dequeue\n3.PrintQueue\n4.Top Element\n0.Exit\n";
		cin>>option;
		switch(option)
		{
		case 1:
			cout<<"Enter the element to Enqueue:\n";
			cin>>z;
			Enqueue(z);
			break;
		case 2:
			z=Dequeue();
			cout<<"The element Dequeued is:\n";
			cout<<z;
			break;
		case 3:
			cout<<"The Elements present in the queue are:\n";
			PrintQueue();
		case 4:
			cout<<"Top element is:\n"+atTop();
		case 0:
			cout<<"Exitingg!";
		default:
			cout<<"Invalid Choice!";
		}
	}while(option!=0);
	
	getchar();
	return 0;
}