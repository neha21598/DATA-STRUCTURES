#include<iostream>
using namespace std;
char stack[100];
struct Node
{
	int data;
	struct Node * next;
};

struct Node* trav=NULL;
struct Node* top=NULL;

void push(int data)
{
	Node* NewNode=new Node;
	NewNode->data=data;
	NewNode->next=NULL;
	if(top==NULL)	
	{
		top=NewNode;
	}
	else
	{
		NewNode->next=top;
		top=NewNode;
	}
}

void pop()
{
	Node* temp;
	if(top==NULL)
	{
		cout<<"Stack is Emptyy!";
	}
	else
	{
	temp=top;
	top=top->next;
	delete temp;
	}
}

void printStack()
{
	trav=top;
	cout<<"The Elements in the Stack are:\n";
	if(trav==NULL)
		cout<<"Stack is EMPTYY!\n";
	else
	{
		while(trav!=NULL)
		{
			cout<<trav->data<<"\t";
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
		cout<<"1.PUSH\n2.POP\n3.PrintStack\n0.Exit\n";
	    cin>>option;
		switch(option)
		{
		case 1:
			cout<<"Enter the Element to PUSH:\n";
			cin>>e;
			push(e);
			break;

		case 2:
			pop();
			break;

		case 3:
			printStack();
			break;

		case 0:
			cout<<"Exiting\n";
			break;
		}
	}while(option!=0);
	getchar();
}