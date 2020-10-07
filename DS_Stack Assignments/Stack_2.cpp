#include<iostream>
using namespace std;
char stack[7];             //creating stack
int toss=-1;               //toss initialization
void push(char a)
{
	toss++;
	stack[toss]=a;
}

void pop()
{
	toss--;
}
int main()
{
	char exp[]="{()}[]";                         //Expression to be checked
	for(int i=0;i<strlen(exp);i++)
	{
		if(exp[i]=='('||exp[i]=='{'||exp[i]=='[')   //checking all opening brackets 
		{
			push(exp[i]);                           //if condition satisfies then push
		continue;                                   //CONTINUED if condition doesn't match with open brackets
		}
		else if(exp[i]==')'||exp[i]=='}'||exp[i]==']') //Checking closing brackets
		{
			if(exp[i]==')')                            //checking particular bracket
			{
				if(stack[toss]=='(')  //checking if opening bracket exist for current closing bracket
				{
					pop();            //pop out if pairs of opening and closing bracket exists!
				}
				else
				{
					cout<<"UNBALANCED EXP";
				break;
				}
			}

			if(exp[i]=='}')
			{
				if(stack[toss]=='{')
				{
					pop();
				}
				else
				{
					cout<<"UNBALANCED EXP";
				break;
				}
			}
			if(exp[i]==']')
			{
				if(stack[toss]=='[')
				{
					pop();
				}
				else
				{
					cout<<"UNBALANCED EXP";
				break;
				}
			}
		}
		if(toss==-1)                    //if stack is empty at the end then condition is Balanced
		{
			cout<<"BALANCED!!!!!";
		}
	}
	getchar();
	return 0;
}