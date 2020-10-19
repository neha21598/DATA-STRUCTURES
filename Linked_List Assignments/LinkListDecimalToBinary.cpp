#include<iostream>
using namespace std;
int cnt=0;
struct Node
{
	int data;
	struct Node* next;
};
struct Node* root=NULL;
struct Node*trav=NULL;

 int result()
{
	int res=0;
	struct Node* trav1=root;
	while(trav1!=NULL)
	{
		res=res+((trav1->data)*pow(2,cnt-1));
		trav1=trav1->next;
		cnt--;
	}
	return res;
}
int insertAtRight(int data)
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
	cnt++;
	return cnt;
}

int main()
{
	insertAtRight(0);
	insertAtRight(1);
	insertAtRight(1);
	insertAtRight(1);
	cout<<"The result is:\n"<<result();
	getchar();
}