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
	bool insert(int);
	void display();
};
    
    Node::Node()
	{
		this->data=0;
		this->next=NULL;
	}

    Node::Node(int a)
	{
		this->data=a;
		this->next=NULL;
	}

    void Node::setData(int a)
    {
	    this->data=a;
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

	Linkedlist:: Linkedlist()
	{
		this->head=NULL;
	}

	bool Linkedlist:: insert(int data)
	{
		Node* NewNode=new Node(data);

        if(NewNode==NULL)
		{
			return false;
		}
		
		if(head==NULL)
		{
			head=NewNode;
			return true;
		}

		Node* temp= head;
		while(temp->getNext()!=NULL)
		{
			temp=temp->getNext();
		}
		NewNode->setNext(temp->getNext());
		temp->setNext(NewNode);
		return true;
	}


void Linkedlist::display()
{
	Node* temp = head;
	while (temp != NULL)
	{
		cout << "\t" << temp->getData();
		temp = temp->getNext();
	}
	cout << endl;
}

	int main()
	{
		Linkedlist L;
		L.insert(10);
		L.insert(20);
		L.insert(30);
		L.display();
		getchar();
	}