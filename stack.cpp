#include<stdio.h>

# define Max 100

int stack[Max];
int top=-1;
int item;

void push(int item)
{
	if(top==Max)
	{
		printf("Overflow");
	}
	else
	{
		stack[top++]=item;
	}
}

int pop()
{
	if(top==-1)
	{
		printf("Underflow");
	}
	else
	{
		return stack[top--];
	}
}

void view()
{
	if(top==-1)
	{
		printf("the stack is empty");
	}
	else
	{
		for(int i=1;i<=top;i++)
		{
			printf("%d",stack[i]);
		}
	}
}

int main()
{
	int ch;
	
	
	printf("Enter 1 for push 2 for pop 3 for view:");
	scanf("%d",&ch);
	
	if(ch==1)
	{
		printf("Enter the element to push: ");
		scanf("%d",&item);
		push(item);
		view();
	}
	
	else if(ch==2)
	{
		item=pop();
		if(item=-1)
		{
			printf("Underflow");
		}
	}
	else if(ch==3)
	{
		view();
	}
}


