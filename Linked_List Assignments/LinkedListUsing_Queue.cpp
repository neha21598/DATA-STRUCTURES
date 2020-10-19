#include<iostream>
using namespace std;
char Q[100];
struct Node
{
	int data;
	struct Node *next;
};

struct Node* front=NULL;
struct Node* rear=NULL;

void EnQueue(int data)
{
	Node* NewNode=new Node;
	NewNode->data=data;
	NewNode->next=NULL;
	if(rear==NULL)
	{
		front=rear=NewNode;
	}
	else
	{
		rear->next=NewNode;
		rear=NewNode;
	}
}

void DeQueue()
{
	Node* trav;
	if(front==NULL)
		cout<<"Queue is EMPTY!";
	else
	{
		trav=front;
		front=front->next;
		delete trav;
	}
}

void PrintQueue()
{
	Node* trav;
	if(front==NULL)
		cout<<"Queue is EMPTY!";
	else
	{
		trav=front;
		while(trav!=NULL)
		{
			cout<<trav->data<<"\n";
			trav=trav->next;
		}
	}
}

int main()
{
	int option,e;
	cout<<"SELECT 1 OPTION:\n";
	do
	{
		cout<<"1.EnQueue\n2.DeQueue\n3.PrintList\n0.Exit\n";
	    cin>>option;
		switch(option)
		{
		case 1:
			cout<<"Enter the Element to ENQUEUE:\n";
			cin>>e;
			EnQueue(e);
			break;

		case 2:
			DeQueue();
			break;

		case 3:
			PrintQueue();
			break;

		case 0:
			cout<<"Exiting\n";
			break;
		}
	}while(option!=0);
	getchar();
}