#include <iostream>
using namespace std;

class Node
{
public :
	int data;
	Node * next;

	Node()
	{
		data=0;
		next=NULL;
	}

	Node(int data)
		{
			data=data;
			next=NULL;
		}
};

class List
{
public:

	Node* head;
	int cnt;
	List()
	{
		head=NULL;
		cnt=0;
	}

bool isEmpty()
{
	if(head == NULL)
 return true;
	else
		return false;
}

void addAtFirst(int data)
{
	Node * newNode= new Node(data);
if(isEmpty())
{

head=newNode;
cnt++;
}
else
{
	newNode->next=head;
	head=newNode;
}
}

void addAtLast(int data)
{
	Node * newNode= new Node(data);
if(isEmpty())
{
head=newNode;
cnt++;
}

else
{
Node * trav;
trav=head;
while(trav->next!=NULL)
{
	trav=trav->next;
}
trav->next=newNode;
cnt++;
}
}

void print()
{
Node * trav=head;
cout<<"Link List Contains Data"<<endl;
while(trav!=NULL)
{
cout<<trav->data<<endl;
trav=trav->next;
}
}

void swapp(Node* n)
{
    Node* trav = n;
    while (trav != NULL && trav->next != NULL)
    {
		int temp;
		temp=trav->data;
		trav->data=trav->next->data;
		trav->next->data=temp;
        trav = trav->next->next;
    }
}
};

int main()
{
List list;
list.addAtFirst(10);
list.addAtLast(20);
list.addAtLast(30);
list.addAtLast(40);
list.print();
cout<<"After Swapping DATA"<<endl;
list.swapp(list.head);
list.print();
getchar();
}