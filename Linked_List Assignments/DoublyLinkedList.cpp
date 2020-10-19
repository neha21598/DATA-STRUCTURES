#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* root=NULL;
struct Node* trav=NULL;
struct Node* trav2=NULL;

void insertAtFirst(int data)
{
	Node* NewNode=new Node;
	NewNode->left=NULL;
	NewNode->right=NULL;
	NewNode->data=data;
	if(root==NULL)
	{
		root=NewNode;
	}
	else
	{
		root->left=NewNode;
		NewNode->right=root;
		root=NewNode;
	}
}

void insertAtLast(int data)
{
	Node* NewNode=new Node;
	NewNode->left=NULL;
	NewNode->right=NULL;
	NewNode->data=data;
	trav=root;
	if(root==NULL)
	{
		root=NewNode;
	}
	else
	{
		while(trav->right!=NULL)
		{
			trav=trav->right;
		}
		trav->right=NewNode;
		NewNode->left=trav;
	}
}

void deleteAtFirst()
{
	if(root==NULL)
	{
		cout<<"List is EMPTY\n";
	}
	else
	{
	trav=root;
	root=root->right;
	root->left=NULL;
	cout<<"The deleted data is:\t"<<trav->data<<"\n";
	delete trav;
	}
}


void deleteAtLast()
{
	if(root==NULL)
	{
		cout<<"List is EMPTY\n";
	}
	else
	{
	trav=trav2=root;
	while(trav->right!=NULL)
	{
		trav2=trav;
		trav=trav->right;
	}
	trav2->right=NULL;
	cout<<"The deleted data is:\t"<<trav->data<<"\n";
	delete trav;
	}
}

void printList()
{
	cout<<"The Elements in the List are:\n";
	trav=root;
	while(trav!=NULL)
	{
		cout<<trav->data<<"\t";
		trav=trav->right;
	}
	cout<<"\n\n";
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