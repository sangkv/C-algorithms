#include<stdio.h>
#include<stdlib.h>

typedef int typeOfData;

typedef struct
{
	typeOfData data;
	struct typeOfNode* next;
}typeOfNode;

typedef struct
{
	typeOfNode* first; /* Pointer first element */
	typeOfNode* last; /* Pointer last element */
}queue;

void initialize(queue* p)
{
	p->first = NULL;
	p->last = NULL;
}

int isEmpty(queue* p)
{
	if(p->first == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int length(queue* p)
{
	int i = 0;
	typeOfNode* q = p->first;
	while(q != NULL)
	{
		q = q->next;
		i++;
	}
	return i;
}

typeOfNode* createNode(typeOfData x)
{
	typeOfNode* p = (typeOfNode*) malloc(sizeof(typeOfNode));
	if(p==NULL)
	{
		return NULL;
	}
	else
	{
		p->data = x;
		p->next = NULL;
		return p;
	}
}

void addQueue(queue* ptr_Q, typeOfData x)
{
	typeOfNode* p = createNode(x);
	if(p != NULL)
	{
		if(isEmpty(ptr_Q)==1)
		{
			ptr_Q->first = p;
			ptr_Q->last = p;
		}
		else
		{
			ptr_Q->last->next = p;
			ptr_Q->last = p;
		}
	}
}

void delQueue(queue* ptr_Q, typeOfData* x)
{
	if(isEmpty(ptr_Q)==1)
	{
		printf("\nQueue is empty!!!");
	}
	else
	{
		typeOfNode* p = ptr_Q->first;
		*x = p->data;
		ptr_Q->first = p->next;
		free(p);
	}
}

int main(int argc, char* argv[])
{
	/* Khai bao hang doi */
	queue Q;
	
	/* Khoi tao hang doi */
	initialize(&Q);
	
	/* Kiem tra do dai hang doi */
	printf("\nLength queue is: %d",length(&Q));
	
	/* Them mot phan tu vao hang doi */
	typeOfData x = 2;
	addQueue(&Q, x);
	addQueue(&Q, 4);
	addQueue(&Q, 8);
	addQueue(&Q, 32);
	addQueue(&Q, 64);
	addQueue(&Q, 128);
	
	/* Lay gia tri phan tu hang doi va xoa phan tu do */
	typeOfData y;
	delQueue(&Q, &y);
	printf("\ndata = %d",y);
	
	printf("\nLength queue is: %d",length(&Q));
	
	
	return 0;
}
