#include<stdio.h>
#include<stdlib.h>

typedef int typeOfItem;

typedef struct
{
	int top;
	typeOfItem nodes[1000]; /* stack with maxSize = 1000 */
}stack;

void initialize(stack* p)
{
	p->top = 0;
}

int isEmpty(stack* p)
{
	if(p->top==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull(stack* p)
{
	if(p->top==1000)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int length(stack* p)
{
	return p->top;
}

void push(stack* p, typeOfItem x)
{
	if(isFull(p)==1)
	{
		printf("\nstack is full");
	}
	else
	{
		p->top++;
		p->nodes[p->top-1] = x;
	}
}

void pop(stack* p, typeOfItem* x)
{
	if(isEmpty(p)==1)
	{
		printf("\nstack is empty");
	}
	else
	{
		*x = p->nodes[p->top-1];
		p->top--;
	}
}

int main(int argc, char* argv[])
{
	/* Khai bao stack */
	stack s;
	
	/* Khoi tao stack */
	initialize(&s);
	
	/* Ung dung stack doi he co so 10 sang co so 2 */
	int a = 50;
	int pn, pd;
	
	pn = a;
	while(pn != 0)
	{
		pd = pn%2;
		push(&s, pd);
		pn = pn/2;
	}
	
	printf("\nSo o he 10 la: %d", a);
	printf("\nSo o he 2 la: ");
	while(isEmpty(&s)==0)
	{
		pop(&s, &pn);
		printf("%d", pn);
	}
	
	return 0;
}
