#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};

struct Node* root=NULL;
struct Node* trav=NULL;

void insertAtFirst(int data)
{
	Node* NewNode=new Node;
	NewNode->data=data;
	NewNode->next=NULL;
	if(root==NULL)
	{
		root=NewNode;
	}
	else
	{
		NewNode->next=root;
		root=NewNode;
	}
}

void insertAtLast(int data)
{
	Node* NewNode=new Node;
	NewNode->data=data;
	NewNode->next=NULL;
	if(root==NULL)
	{
		root=NewNode;
	}
	else
	{
		trav=root;
		while(trav->next!=NULL)
		{
			trav=trav->next;
		}
		trav->next=NewNode;
	}
}

void deleteAtFirst()
{
	if(root==NULL)
	{
		cout<<"List is EMPTY";
	}
	else
	{
	trav=root;
	root=root->next;
	delete trav;
	}
}

void deleteAtLast()
{
	if(root==NULL)
		cout<<"List is Empty";
	else
	{
		trav=root;
		Node* trav2=root;
		while(trav->next!=NULL)
		{
			trav2=trav;
			trav=trav->next;
		}
		trav2->next=NULL;
		delete trav;
	}
}

void printList()
{
	Node *trav;
	trav=root;
	while(trav!=NULL)
	{
		cout<<trav->data<<"\n";
		trav=trav->next;
	}
}

void searchData(int data)
{
	trav=root;
	while(trav!=NULL)
	{
		if(trav->data==data)
		{
			cout<<"Element Found\n";
		break;
		}
		else
		{
			trav=trav->next;
		}
		cout<<"Element NOT Found!!\n";
		break;
	}
}

int main()
{
	int option,e;
	cout<<"SELECT 1 OPTION:\n";
	do
	{
		cout<<"1.InsertAtFirst\n2.InsertAtLast\n3.DeleteAtFirst\n4.DeleteAtLast\n5.PrintList\n6.Search Element\n0.Exit\n";
	    cin>>option;
		switch(option)
		{
		case 1:
			cout<<"Enter the Element to AddFirst:\n";
			cin>>e;
			insertAtFirst(e);
			break;

		case 2:
			cout<<"Enter the Element to AddLast:\n";
			cin>>e;
			insertAtLast(e);
			break;

		case 3:
			cout<<"Enter the Element to DeleteAtFirst:\n";
			cin>>e;
			deleteAtFirst();
			break;

        case 4:
			cout<<"Enter the Element to DeleteAtLast:\n";
			cin>>e;
			deleteAtLast();
			break;
			
		case 5:
			printList();
			break;

		case 6:
			int key;
			cout<<"Enter Element to be Found:\n";
			cin>>key;
			searchData(key);
			break;

		case 0:
			cout<<"Exiting\n";
			break;


		}
	}while(option!=0);
	getchar();
}