#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<stdio.h>
#include<math.h>

void error()
{	
	printf("\n Given postfix is incorrect");
	exit(0);
	}

void push(float stack[],int *top,float num)
{	stack[++(*top)]=num;
}
float pop(float stack[],int *top)
{
	if(*top==-1)error();
	return(stack[(*top)--]);
}
float eval(char postfix[20])
{
	float stack[20],op1,op2;
	int i=-1,top=-1;
	while(postfix[++i]!='\0')
	{
		if(isdigit(postfix[i]))
			push(stack,&top,postfix[i]-48);
		else
		{
		op2=pop(stack,&top);
		op1=pop(stack,&top);
		switch(postfix[i])
		{
		case '^':
		push(stack,&top,pow(op1,op2));
		break;	
		case '*':
		push(stack,&top,op1*op2);
		break;	
		case '/':
		push(stack,&top,op1/op2);
		break;	
		case '+':
		push(stack,&top,op1+op2);
		break;	
		case '-':
		push(stack,&top,op1-op2);
		break;	
		}
	}
}
if(top) error();
return (pop(stack,&top));
}
void main()
{
	char postfix[20];
	printf("\nEnter the postfix expression:");
	scanf("%s",postfix);
	printf("\nValue of the postfix expression is %.2f",eval(postfix));
	}
	
