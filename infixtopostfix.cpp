#include<iostream>
using namespace std;
void push(char *stack,int *top,char val)
{   *top=*top+1;
	*(stack+*top)=val;
}
char pop(char *stack,int *top)
{
	char dataout=*(stack+*top);
	*top=*top-1;
	return dataout;
}
char stacktop(char *stack,int *top)
{
	char dataout=*(stack+*top);
	return dataout;
}
int priority(char c)
{
	if(c=='^')
	{
		return 3;
	}
	else if(c=='*'||c=='/')
	{
		return 2;
	}
	else if(c=='+'||c=='-')
	{
		return 1;
	}
	else if(c=='(')
	{
		return 0;
	}
	else
	{
		return -1;
	}
}
void intopostfix(string s)
{
	char Stack[10];
	string postfix;
	int top=-1;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='(')
		{
			push(Stack,&top,s[i]);
		}
		else if(s[i]==')')
		{
			char d;
			d=pop(Stack,&top);
			while(d!='(')
			{
				postfix+=d;
				d=pop(Stack,&top);
			}
		}
		else if(s[i]=='*'||s[i]=='/'||s[i]=='+'||s[i]=='-')
		{
			char d;
			while(top!=-1 && priority(s[i])<=priority(stacktop()))
			{
				d=pop(Stack,&top);
				postfix+=d;
			}
			push(Stack,&top,s[i]);
		}
		else
		{
			postfix+=s[i];
		}

	}
	while(top!=-1)
	{
		char d;
		d=pop(Stack,&top);
		postfix+=d;
	}
    cout<<"The postfix expression is :"<<endl;
	cout<<postfix;
}
int main()
{
	string exp;
	cout<<"enter the infix expression: ";
	cin>>exp;
	intopostfix(exp);
	
	return 0;
}
