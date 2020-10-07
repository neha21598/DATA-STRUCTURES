#include<iostream>
using namespace std;
int stack[20],toss=-1;
void push(int a)
{
	toss++;
	stack[toss]=a;
}
void printStack()
{
	for(int i=toss;i>-1;i--)
	{
		cout<<stack[toss];
	}
}
int pop()
{
	int temp;
	temp=stack[toss--];
	return temp;
}

void fun(int no)
{
	while(no!=0)
	{
		int rem=no%2;
		no=no/2;
		push(rem);
	}
	while(toss!=-1)
	{
		int arr= pop();
		cout<<arr;
	}
}
int main()
{
	int no;
	cout<<"Enter a Number\n";
	cin>>no;
	fun(no);
	printStack();
	getchar();
	return 0;
}