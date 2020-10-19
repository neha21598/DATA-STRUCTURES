#include<iostream>
#include<string.h>
using namespace std;
char prefix[100],stack[100];
int z=0,top=-1;

void push(char a)
{
	top++;
	stack[top]=a;
}
int pop()
{
	char temp;
	temp=stack[top--];
	return temp;
}
int atTop()
{
    return stack[top];
}
int priority(char a)
{
	switch(a)
	{
	case '+':case '-':
		return 1;
		break;
	case '*':case '/':case '%':
		return 2;
		break;
	case '^':
		return 3; break;
	case ')':
		return 0;
		break;
	}
}
void infixToPrefix(char infix[])
{
    int str=strlen(infix);
	for(int i=str;i>=0;i--)
	{
		if((infix[i]>='a' && infix[i]<='z')||(infix[i]>='A' && infix[i]<='Z'))
		{
			prefix[z++]=infix[i];
		} 
		else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='%'||infix[i]=='^'||infix[i]==')'||infix[i]=='(')
		{
			if(top==-1)
			{
				push(infix[i]);
			}
			else
			{
				int prio1=priority(atTop());
				int prio2=(infix[i]);

				if(infix[i]==')')
				{
					push(infix[i]);
				}
				else if(infix[i]=='(')
				{
					while(top!=-1)
					{
						char temp;
						temp=pop();
						if(temp!=')')
						{
							prefix[z++]=temp;
						}
					}
				}

				else if(prio1<prio2)
				{
					push(infix[i]);
				}
				else 
				{
					while(top!=-1)
					{
					char temp;
					temp=pop();
					prefix[z++]=temp;
					}
					push(infix[i]);
				}
			}
		}

		
	}
	while(top!=-1)
	{
		char temp;
		temp=pop();
		prefix[z++]=temp;
	}
}

void printExpression()
{
    int str=strlen(prefix);
	cout<<"The Prefix Expression is:\n";
	for(char i=str;i>=0;i--)
	{
		cout<<prefix[i];
	}
}

int main()
{
	char infix[20];
	cout<<"Enter the Infix Expression:\n";
	cin>>infix;
	infixToPrefix(infix);
	printExpression();
	getchar();
	return 0;
}
