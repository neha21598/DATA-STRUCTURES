#include<iostream>
using namespace std;
char stack[100],postfix[100];
int top,z;

void initStack()
{
	top=-1;
}
void push(char e)
{
	top++;
	stack[top]=e;
}

int isEmpty()
{
	if(stack[top]!=-1)
		return 1;
	else
		return 0;
}

int atTop()
{
	return stack[top];
}

char pop()
{
	char e=stack[top];
	top--;
	return e;
}

void printStack()
{
	for(int i=top;i>-1;i--)
	{
		cout<<stack[i];
	}
}

int priority(char e)
{
	switch(e)
	{
	case '+':case '-':
		return 1;
		break;
	case '/':case '*':case '%':
		return 2;
		break;
	case '^':
		return 3;
		break;
	case '(':
		return 0;
		break;
	}
}

int main()
{
	int prio1,prio2;
	char infix[100];
	cout<<"Enter the infix Expression:";
	cin>>infix;

	for(int i=0;i<strlen(infix);i++)
	{
		if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z'))
		{
				postfix[z] = infix[i];
			    z++;
		}

		else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%' || infix[i]=='^' || infix[i]=='(' || infix[i]==')' )
		{
			if(top==-1)
			{
				push(infix[i]);
			}
			else
			{
				prio1=priority(atTop());
				prio2=priority(infix[i]);

				if(infix[i]=='(')
				{
					push(infix[i]);
				}

				else if(infix[i]==')')
				{
					while(top!=-1)
					{
						char temp = pop();
						if(temp!='(')
						{
						   postfix[z] = temp;
					    	z++;
						}
					}
				}

				else if(prio2<=prio1)
				{
					while(top!=-1)
					{
						postfix[z] = pop();
						z++;
					}
					push(infix[i]);
				}
				else
				{
					push(infix[i]);
				}
			}
		}
	}

	while(top!=-1)
	{
		postfix[z] = pop();
			z++;
	}
	//Print the postfix expression
	cout<<"Postfix Expression is:";
	for(int i=0;postfix[i]!='\0';i++)
	{
		cout<<postfix[i];
	}
	getchar();
return 0;
}

