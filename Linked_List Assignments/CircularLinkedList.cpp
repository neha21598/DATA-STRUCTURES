#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

struct Node* root=NULL;
struct Node* last=NULL;
struct Node* trav=NULL;

void insertAtFirst(int data)
{
	Node* NewNode=new Node;
	NewNode->data=data;
	NewNode->next=NULL;
	if(root==NULL)
	{
		root=last=NewNode;
		last->next=root;
	}
	else
	{
		NewNode->next=root;
		root=NewNode;
		last->next=root;
	}
}

void insertAtLast(int data)
{
	Node* NewNode=new Node;
	NewNode->data=data;
	NewNode->next=NULL;
	if(root==NULL)
	{
		root=last=NewNode;
		last->next=root;
	}
	else
	{
	last->next=NewNode;
	last=NewNode;
	last->next=root;
	}
}

void deleteAtFirst()
{
	if(root==NULL)
	{
		cout<<"List is EMPTY!";
	}
	else
	{
		Node* temp=root;
		root=root->next;
		cout<<"The Node Deleted is:\n "<<temp->data<<"\n";
		last->next=root;
		delete temp;
	}
}

void deleteAtLast()
{
	Node* trav=root;
	if(root==NULL)
	{
		cout<<"List is EMPTY!\n";
	}
	else
	{
		while(trav->next!=last)
		{
			trav=trav->next;
		}
		last=trav;
		trav=trav->next;
		cout<<"The Node deleted is:\n "<<trav->data<<"\n";
		last->next=root;
		delete trav;
	}
}

void printList()
{
	Node* trav=root;
	cout<<"The Elements in the List are:\n";
	if(root==NULL)
	{
		cout<<"List EMPTY!";
	}
	else
	{
	do
	{
		cout<<trav->data<<"\t";
		trav=trav->next;
	}while(trav!=root);
	cout<<"\n\n";
	}
}

int main()
{
	int option,e;
	cout<<"Select any 1 Option:\n";
	do
	{
		cout<<"1.InsertFirst\n2.InsertLast\n3.DeleteFirst\n4.DeleteLast\n5.Print List\n0.Exit\n";
		cin>>option;
		switch(option)
		{
		case 1:
			cout<<"Enter the Element to Insert First:\n ";
			cin>>e;
			insertAtFirst(e);
			break;
		case 2:
			cout<<"Enter the Element to Insert Last:\n ";
			cin>>e;
			insertAtLast(e);
			break;
		case 3:
			deleteAtFirst();
			break;
		case 4:
			deleteAtLast();
			break;
		case 5:
			printList();
			break;
		case 0:
			cout<<"Exiting!!";
			break;
		default:
			cout<<"Invalid Option Selected!";
		}
	}while(option!=0);
}