#include<iostream>
using namespace std;
 struct Node
 {
	 int data;
	 struct Node* left;
	 struct Node* right;
 };

 struct Node* root=NULL;

 Node* createNode(int data)
 {
	 Node* NewNode=new Node;
	 NewNode->data=data;
	 NewNode->left=NULL;
	 NewNode->right=NULL;
	 return NewNode;
 }

void insertNode(Node* root,Node* n)
{
	if(root==NULL)
	{
		root=n;
	}
	
	else
	{
		if((n->data)<(root->data))
		{
			if(root->left==NULL)
			{
				root->left=n;
			}
			else
			{
				insertNode(root->left,n);
			}
		}
		
		else 
		{
			if(root->right==NULL)
			{
				root->right=n;
			}
			else
			{
				insertNode(root->right,n);
			}
		}
	}
}

void inorder(Node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<"\t";
		inorder(root->right);
	}
}

void preorder(Node* root)
{
	if(root!=NULL)
	{
		cout<<root->data<<"\t";
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(Node* root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<"\t";
	}
}

int main()
{
	root=createNode(10);
	//insertNode(root,createNode(10));
	insertNode(root,createNode(5));
	insertNode(root,createNode(7));
	insertNode(root,createNode(100));
	insertNode(root,createNode(50));
	cout<<"Inorder Sequence:\n";
	inorder(root);
	cout<<"\nPreorder Sequence:\n";
	preorder(root);
	cout<<"\nPostrder Sequence:\n";
	postorder(root);
	getchar();
}