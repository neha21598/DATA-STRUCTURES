#include<iostream>
using namespace std;
int s[100],maxSize,toss,e,choice;
void initStack(int size)
{
	maxSize=size;
	toss=-1;
}

void push(int e)
{
   toss++;
   s[toss]=e;
}

int isFull()
{
	if(toss==maxSize-1)
	{
		return 1;
	}
	else
		return 0 ;
}

int pop()
{
   int temp=s[toss];
   toss--;
   return temp;
}

int isEmpty()
{
	if(toss==-1)
		return 1;
	else
		return 0;
}

void printStack()
{
	int i;
	for(int i=toss;i>-1;i--)
	{
		cout<<s[i]<<"\t";
	}
}

int atTop()
{
	return s[toss];
}

int main()
{
	int size,choice;
	cout<<"Enter Size:";
	cin>>size;
	initStack(size);
	do
	{
		cout<<"1.Push \n 2.Pop \n 3.atTop \n 4.printStack \n 0.Exit\n";
		cout<<"Enter your choice\n";
		cin>>choice;
		switch(choice)
		{
		case 1:
			if(isFull()==1)
				cout<<"Stack is FULL";
			else
			{
				cout<<"Enter element";
			cin>>e;
			push(e);
			}
			break;

		case 2:
			if(isEmpty()==1)
				cout<<"Stack is Empty";
			else
			{
				e=pop();
				cout<<"You popped"<<e;
			}
			break;

		case 3:
			if(isEmpty()==1)
				cout<<"Your stack is Empty";
			else
			{
				e=atTop();
				cout<<"Top element is: "<<e;
			}
			break;

		case 4:
			if(isEmpty()==1)
				cout<<"Stack is Empty";
			else
			{
				printStack();
			}
			break;

		case 0:
			cout<<"Exiting";

		default:
			cout<<"Invalid Choice!";
			break;
		}
	}while(choice!=0);
}