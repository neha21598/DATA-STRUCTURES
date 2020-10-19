#include<iostream>
using namespace std;
struct Node
{
	int data;
	struct Node* next;
};
struct Node* root=NULL;
struct Node* trav=NULL;
struct Node* last=NULL;

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

void rotate(int cycles)
{
	while(cycles!=0)
	{
		int temp;
		temp=root->data;
		root->data=last->data;
		last=last->next;
		root=root->next;
		root->next->data=root->data;
		root->data=temp;
		cycles--;
	}
}

void printList()
{
	trav=root;
	do
	{
		cout<<trav->data<<"---->";
		trav=trav->next;
	}while(trav!=root);
}

int main()
{
	int cycle;
	insertAtLast(10);
	insertAtLast(20);
	insertAtLast(30);
	insertAtLast(40);
	cout<<"Enter cycles:\n";
	cin>>cycle;
	rotate(cycle);
	printList();
	getchar();
}