#include<iostream>
using namespace std;
int top,maxSize;
char stack[100];
void initStack(int size)
{
	maxSize=size;
	top=-1;
}
int isFull()
{
	if(top==maxSize)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
void push(int p)
{
	if(isFull())
	{
		cout<<"Stack is full";
	}
	else
	{
	top++;
	stack[top]=p;
	}
}

int atTop()
{
	return stack[top];
}

int isEmpty()
{
	if(top==-1)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}
 
void pop()
{
	if(isEmpty())
	{
		cout<<"Stack is Empty";
	}
	else
	{
		top--;
	}
}


int main()
{
	int size_stack,result;
	char str[20];
	cout<<"Enter size of Stack:\n";
	cin>>size_stack;
	initStack(size_stack);
	cout<<"\n Enter the Expression to be Evaluated:\n"; 
	cin>>str;
	for(int i=0;i<sizeof(str);i++)
	{
		if(str[i]>='0' && str[i]<='9')
		{
			push(str[i]-'0');
		}

		else if(str[i]=='+'||str[i]=='-'||str[i]=='*'||str[i]=='/'||str[i]=='%')
		{
			int first=atTop();
			pop();
			int second=atTop();
			pop();
			switch(str[i])
			{
			case '+':
				push(first+second);
				break;

			case '-':
				push(first-second);
				break;

			case '*':
				push(first*second);
				break;

			case '/':
				push(first/second);
				break;

			case '%':
				push(first%second);
				break;
			}
		}
	}
	result=atTop();
	cout<<"The result of your Expression is:\n"<<result;
	getchar();
	return 0;

}