#include<iostream>
using namespace std;
char s[100];
int e,tos=-1;

void push(char a)
{
	tos++;
	s[tos]=a;
}

char pop()
{
	char temp=s[tos];
	tos--;
	return temp;
}

int main()
{
	char str[20];
	cout<<"Enter String:\n";
	cin>>str;
	for(int i=0;str[i]!='\0';i++)
	{
		push(str[i]);
	}

	for(int i=tos;s[tos]>-1;i--)
	{
		char a=pop();
		cout<<a;
	}
	
	getchar();
}