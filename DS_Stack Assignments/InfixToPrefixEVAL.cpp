#include<iostream>
#include<string.h>
using namespace std;
char prefix[100],stack[100];
int top=-1;

void push(int data)
{
    top++;
    stack[top]=data;
}

int pop()
{
    int temp=stack[top];
    top--;
    return temp;
}

int atTop()
{
    return stack[top];
}

void prefixEval(char infix[])
{
    int str=strlen(infix)-1;
    for(int i=str;i>=0;i--)
    {
        if(infix[i]>='0' && infix[i]<='9')
        {
            push(infix[i]-'0');
        }
        else if(infix[i]=='+'||infix[i]=='-'||infix[i]=='*'||infix[i]=='/'||infix[i]=='^')
        {
            int first=pop();
            int second=pop();
            switch(infix[i])
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
                
                case '^':
                push(first^second);
                break;
            }
        }
    }
}

int main()
{
    char infix[100];
    cout<<"Enter the Infix Expression:\n";
    cin>>infix;
    prefixEval(infix);
    int res=atTop();
    cout<<res;
    return 0;
}