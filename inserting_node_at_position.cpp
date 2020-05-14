#include<iostream>
using namespace std;
class Node
{
	int data;
	Node* next;

public:
	Node();
	Node(int);
	void setData(int);
	int getData();
	void setNext(Node*);
	Node* getNext();
};

class Linkedlist
{
	Node* head;

public:
	Linkedlist();
	bool insert_position(int,int);
	void display();
};

Node:: Node()
{
	this->data=0;
	this->next=NULL;
}

Node:: Node(int data)
{
	this->data=data;
	this->next=NULL;
}

void Node:: setData(int data)
{
	this->data=data;
}

int Node:: getData()
{
	return this->data;
}

void Node:: setNext(Node* Next)
{
	this->next=Next;
}

Node* Node:: getNext()
{
	return this->next;
}

Linkedlist::Linkedlist()
{
	this->head=NULL;
}

bool Linkedlist:: insert_position(int data,int pos)
{
	if(pos<=0)
	{
		return false;
	}
	Node* NewNode= new Node(data);

	if(NewNode==NULL)
	{
		return false;
	}

	if(head==NULL)
	{
		head=NewNode;
		return true;
	}

	if(pos==1)
	{
		NewNode->setNext(head);
		head=NewNode;
		return true;
	}

	Node* temp=head;
	
	for(int i=1;i<pos-1;i++)
	{
		temp=temp->getNext();
		if(temp==NULL)
		{
			delete NewNode;
			return false;
		}
	}
	NewNode->setNext(temp->getNext());
    temp->setNext(NewNode);
	return true;
}

void Linkedlist::display()
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->getData()<<"\t";
		temp=temp->getNext();
	}
}

int main()
{
	Linkedlist L;
	L.insert_position(70,7);
	L.display();
	getchar();
}